#include "Model.h"

Model::Model(const GLchar* path)
{
	this->loadModel(path);
}

void Model::Draw(Shader shader)
{
	for (int i = 0; i < this->meshes.size(); i++)
	{
		this->meshes[i].Draw(shader);
	}
}

void Model::loadModel(string path)
{
	Assimp::Importer importer;
	const aiScene* aiScene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	//验证读取是否错误
	if(!aiScene || aiScene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !aiScene->mRootNode)
	{
		cout << "ASSIMP ERROR!  " << importer.GetErrorString() << endl;
		return;
	}
	//如果正确
	this->directory = path.substr(0, path.find_last_of('/')); //这一步就需要保证输入必须是 / 作为下级目录
	cout << "Model::loadModel\npath " << path << " and import successfully!" << "\ndirectory " << this->directory << endl;
	this->processNodes(aiScene->mRootNode, aiScene);
}

void Model::processNodes(aiNode* node, const aiScene* scene)
{
	cout << "Model::processNode::\t meshNum:" << node->mNumMeshes << "\tnodeNum:" << node->mNumChildren << endl;
	//处理这个节点下的Meshes
	for (int i = 0; i < node->mNumMeshes; i++)
	{
		cout << "Model::processNode::MeshIndex = " << i << endl;
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]]; //node这种子节点下的mMeshes里只是索引值，真正的数据在scene里的mMeshes中
		this->meshes.push_back(processMeshes(mesh, scene));
	}
	//处理子节点
	for (int j = 0; j < node->mNumChildren; j++)
	{
		cout << "Model::processNode::NodeIndex = " << j << endl;
		aiNode* childnode = node->mChildren[j];
		processNodes(childnode, scene);
	}
}

//这一步是把assimp里的aiMesh类关联到我们自己创建的Mesh类中
Mesh Model::processMeshes(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<GLuint> indices; //这是EBO中的索引变量
	vector<Texture> textures;

	cout << "Model::ProcessMesh::\tvertexNum:" << mesh->mNumVertices << "\tfaceNum:" << mesh->mNumFaces << "\tmatrialNum:" << mesh->mMaterialIndex << endl;
	//处理顶点{顶点坐标，法线坐标，贴图坐标}
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		//—————处理顶点坐标—————
		Vertex vertex;
		glm::vec3 vector3;
		vector3.x = mesh->mVertices[i].x;
		vector3.y = mesh->mVertices[i].y;
		vector3.z = mesh->mVertices[i].z;
		vertex.Position = vector3;
		if (i == 0 || i == 1 || i == 2)
			cout << "Model::ProcessMesh::No." << i << "Vertex (x,y,z)=(" << vector3.x << "," << vector3.y << "," << vector3.z << ")\n";
		//—————处理法线坐标—————
		vector3.x = mesh->mNormals[i].x;
		vector3.y = mesh->mNormals[i].y;
		vector3.z = mesh->mNormals[i].z;
		vertex.Normal = vector3;
		//—————处理贴图坐标（只关心第一个贴图）—————
		//这个存储方式是二维数组，[No.1]表示这是此顶点上的第几个纹理
		//[No.2]表示这是第几个点，似乎和正常的父子关系有点反
		if (mesh->mTextureCoords[0])
		{
			glm::vec2 vector2;
			vector2.x = mesh->mTextureCoords[0][i].x;
			vector2.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoord = vector2;
			if (i == 0 || i == 1 || i == 2)
				cout << "Model::ProcessMesh::No." << i << "TexCoord (u,v)=(" << vector2.x << "," << vector2.y << ")\n";
		}
		else
		{
			cout << "Model::ProcessMesh::This Model Don't have a Texture" << endl;
			vertex.TexCoord = glm::vec2(0.0f, 0.0f);
		}
		//最后，pushback
		vertices.push_back(vertex);
	}

	//处理索引，在assimp中关系是这样的，Mesh->face->index，也就是说面是一个中间的，面中包括了顶点索引
	for (int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	//处理贴图，这里我们默认对于每个Mesh只允许他有一个贴图，也就是texture最多会有size()=2，diffuse和specular各一张
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		vector<Texture> diffuseMaps = this->loadMaterialTexture(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		vector<Texture> specularMaps = this->loadMaterialTexture(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}
	return Mesh(vertices, indices, textures);
}


vector<Texture> Model::loadMaterialTexture(aiMaterial* mat, aiTextureType type, string type_name)
{
	cout << "Model::loadMaterialTexture:: Type:" << type_name << ",  TextureCount:" << mat->GetTextureCount(type) << "\n";
	vector<Texture> textures;
	for (int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str); //这一步取出贴图的path
		Texture texture;
		texture.path = str;
		texture.type = type_name;
		texture.id = this->setTextureID(str.C_Str(), this->directory);
		textures.push_back(texture);
	}
	return textures;
}


GLuint Model::setTextureID(const string name, string dir)
{
	string filePath = dir + "/" + name;
	cv::Mat woodPic = cv::imread(filePath, 1);
	cout << "Model::setTextureID:\n加载贴图" << filePath << endl;
	if (woodPic.empty())
	{
		cout << "ERROR 贴图文件加载失败！" << endl;
	}
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	GLint width, height;
	width = woodPic.cols;
	height = woodPic.rows;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, woodPic.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}