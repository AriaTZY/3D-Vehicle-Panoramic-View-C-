#pragma once
#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Shader
{
public:
	GLuint Program;
	Shader(const GLchar * vertexPath, const GLchar * fragPath);
	void Use();
};

#endif // !GL_SHADER_H
