#pragma once
#ifndef __MODEL_H_
#define __MODEL_H

#include <glew.h>
#include <iostream>
#include "Mesh.h"
#include <string>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <opencv2/opencv.hpp>
#include <SOIL.h>

class Model
{
public:
	Model(const GLchar *path);
	void Draw(Shader shader);
private:
	//模型数据
	vector<Mesh> meshes;
	string directory;
	void loadModel(string path);
	void processNodes(aiNode* node, const aiScene* scene);
	Mesh processMeshes(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTexture(aiMaterial* mat, aiTextureType type, string typename);
	GLuint setTextureID(string path, string dir);
};


#endif // !__MODEL_H_