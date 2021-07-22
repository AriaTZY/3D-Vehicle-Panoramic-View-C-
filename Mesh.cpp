#include "Mesh.h"


Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	this->setupMesh();
}

//这个是在配置渲染器VBO，VAO，EBO和顶点解释器
void Mesh::setupMesh()
{
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoord));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}


void Mesh::Draw(Shader shader)
{
	GLuint diffuseNum = 1;
	GLuint specularNum = 1;
	for (int i = 0; i < this->textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		//接下来就是进行字符串游戏
		stringstream ss;
		string num;
		string name = this->textures[i].type;
		if (name == "texture_diffuse")
			ss << diffuseNum++;
		else if (name == "texture_specular")
			ss << specularNum++;
		num = ss.str();
		glUniform1i(glGetUniformLocation(shader.Program, (name + num).c_str()), i); //这个是设置唯一标识符
		glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
	}

	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	
	//解绑刚刚的
	for (int i = 0; i < this->textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}