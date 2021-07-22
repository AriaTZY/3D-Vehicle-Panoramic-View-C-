#pragma once
#ifndef GL_MESH_H
#define GL_MESH_H

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <assimp/Importer.hpp>
#include "Shader.h"
using namespace std;

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoord;
};

struct Texture
{
	GLuint id;
	string type;
	aiString path;
};

class Mesh
{
public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	void Draw(Shader shader);
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();
};

#endif // !GL_MESH_H