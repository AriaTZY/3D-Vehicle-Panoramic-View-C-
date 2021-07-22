#include "Shader.h"

Shader::Shader(const GLchar * vertexPath, const GLchar * fragPath)
{
	//����Ĺ������������ļ��Ĵ򿪹���
	std::string vertexProgramSource;
	std::string fragmentProgramSource;
	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	vertexFile.exceptions(std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::badbit);
	try
	{
		vertexFile.open(vertexPath);
		fragmentFile.open(fragPath);
		std::stringstream vertexStream, fragStream;
		vertexStream << vertexFile.rdbuf();
		fragStream << fragmentFile.rdbuf();
		fragmentFile.close();
		vertexFile.close();
		vertexProgramSource = vertexStream.str();
		fragmentProgramSource = fragStream.str();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const GLchar* vShaderCode = vertexProgramSource.c_str();
	const GLchar* fShaderCode = fragmentProgramSource.c_str();
	//���б�������
	//Shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	this->Program = glCreateProgram();
	glAttachShader(Program, vertexShader);
	glAttachShader(Program, fragmentShader);
	glLinkProgram(Program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Shader::Use()
{
	glUseProgram(this->Program);
}