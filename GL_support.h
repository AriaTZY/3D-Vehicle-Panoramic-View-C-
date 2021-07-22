#pragma once
#define GLEW_STATIC
#ifndef __GL_SUPPORT_
#define __GL_SUPPORT_

#include <glew.h>
#include <glfw3.h>
#include <opencv2/opencv.hpp>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "CV_support.h"
#include "Shader.h"
#include "Model.h"

using namespace std;


//-----------OpenGL全局变量声明区-------------------
const int CAMERA_INDEX[4] = {1,0,5,4};
const GLuint SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;


//-----------函数声明区----------------
int renderVista();
int renderVista_RealTime();
void overlapping_Projection();
int renderVista_RealTime_FromImages();

#endif // !__GL_SUPPORT_