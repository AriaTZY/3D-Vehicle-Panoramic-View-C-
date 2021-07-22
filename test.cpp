#include <iostream>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <opencv2/opencv.hpp>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Shader.h"
#include "Model.h"

//这是有关声明静态数组的宏定义
const int roundDelta = 30, doomDelta = 15;
const int verticesNumber = (int)((360 / roundDelta)*(90 / doomDelta) * 6);

using namespace std;
using namespace cv;

const GLuint WIDTH = 800, HEIGHT = 600;
int drawRectangle();
void rotateTexture();
int drawBall();
void DrawModel();
int renderVista();
void drawBox();

////着色器渲染源码
////顶点着色器
//const GLchar * vertexShaderSource = "#version 330 core\n"
//"layout(location=0) in vec3 position;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"  //这个就是预定义的gl_position
//"}\0";
//
////片段着色器
//const GLchar * fragmentShaderSource = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\0";

//这是进行贴图的静态编译
////顶点着色器
//const GLchar *vertexShaderSource = "#version 330 core\n"
//"layout(location=0) in vec3 position;\n"
//"layout(location=1) in vec2 texCoodr;\n"
//"out vec2 TexCoodr;\n"
//"void main(){\n"
//"gl_Position = vec4(position, 1.0f);\n"
//"TexCoodr = texCoodr;}\0";
//
////片段着色器
//const GLchar *fragmentShaderSource = "#version 330 core\n"
//"in vec2 TexCoodr;\n"
//"out vec4 color;\n"
//"uniform sampler2D ourTexture;\n"
//"void main(){\n"
//"color = texture(ourTexture, TexCoodr);\n"
//"}\0";

//实验转动变化的
const GLchar *vertexShaderSource = "#version 330 core\n"
"layout(location=0) in vec3 position;\n"
"layout(location=1) in vec2 texCoodr;\n"
"out vec2 TexCoodr;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 perspective;\n"
"void main(){\n"
"gl_Position = perspective * view * model * vec4(position, 1.0f);\n"
"TexCoodr = texCoodr;}\0";

//片段着色器
const GLchar *fragmentShaderSource = "#version 330 core\n"
"in vec2 TexCoodr;\n"
"out vec4 color;\n"
"uniform sampler2D ourTexture;\n"
"void main(){\n"
"color = texture(ourTexture, TexCoodr);\n"
"}\0";

GLboolean keys[1024];
double last_x, last_y, deltaX = 0, deltaY = 0;
bool first_mouse_in = true;
//欧拉角
GLfloat pitch = 0.0f, yaw = 0.0f, aspect = 45.0f; //最后一个是摄像机视角


void keycallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
	{
		std::cout << "用户按下退出键" << endl;
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (action == GLFW_PRESS)
	{
		keys[key] = GL_TRUE;
	}
	else if (action == GLFW_RELEASE)
	{
		keys[key] = GL_FALSE;
	}
}

void mousecallback(GLFWwindow * window, double x, double y)
{
	GLfloat sensitive = 0.05f;
	if (!first_mouse_in)
	{
		pitch += sensitive * (y - last_y);
		yaw += sensitive * (x - last_x);
	}
	last_y = y;
	last_x = x;
	first_mouse_in = false;
	/*yaw = -((x - WIDTH / 2) / WIDTH * 180.0f);
	pitch = +((y - HEIGHT / 2) / HEIGHT * 180.0f);*/
	//cout << "pitch = " << pitch << "yaw = " << yaw << endl;
}

void scroll_callback(GLFWwindow *window, double x_offset, double y_offset)
{
	if (aspect < 1.0f)
		aspect = 1.0f;
	else if (aspect > 60.0f)
		aspect = 60.0f;
	else
		aspect -= y_offset;
}

int main()
{
	//drawBox();
	renderVista();
	//drawBall();
	//drawRectangle();
	//rotateTexture();
	DrawModel();
	return 0;
}

void rotateTexture() {
	//glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "ROTATE", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keycallback);
	glfwSetCursorPosCallback(window, mousecallback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);// 限制鼠标放在窗口内

	//glew
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, WIDTH, HEIGHT);

	//开启深度测试
	glEnable(GL_DEPTH_TEST);

	//Shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
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
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//point
	GLfloat vertexes[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	
	//VAO
	GLuint VAO, VBO, EBO;
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);
	//glVertexAttribPointer();//进行补充
	//glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	//texture
	Mat woodPic = imread("D:\\show_pic\\texture\\wood.jpg", 1);
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


	//定义摄像机相关变量
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
	//移动的时间差
	GLfloat deltaTime = 0.0f;
	GLfloat currentTime = 0.0f;
	GLfloat lastTime = 0.0f;
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.4f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);
		//进行直线平移摄像机
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(30.0f), (GLfloat)(800.0f / 600.0f), 0.1f, 50.0f);
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -8.0f));
		//使用鼠标操作改变摄像机角度，这里知识暂时改变欧拉角
		/*directionPos.y = sin(glm::radians(pitch + 180.0));
		directionPos.z = cos(glm::radians(pitch + 180.0)) * cos(glm::radians(yaw));
		directionPos.x = sin(glm::radians(yaw));
		directionPos = glm::normalize(directionPos);*/
		//cout << "pitch = " << pitch << endl;
		//这个view是摄像机投影矩阵
		glm::mat4 view;
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 3.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE) //向深度移动
			cameraPos += moveSpeed * directionPos;
		if (keys[GLFW_KEY_S] == GL_TRUE) //向出来移动
			cameraPos -= moveSpeed * directionPos;
		if (keys[GLFW_KEY_A] == GL_TRUE) //向左边移动
			cameraPos += moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		if (keys[GLFW_KEY_D] == GL_TRUE) //向右边移动
			cameraPos -= moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		view = glm::lookAt(cameraPos, glm::vec3(0.0f, 0.0f, -8.0f), upPos);
		
		//对uniform变量赋值
		GLuint uniformLocation = glGetUniformLocation(shaderProgram, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shaderProgram, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shaderProgram, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	std::cout << "窗口关闭" << endl;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
}


int drawRectangle()
{
	//进行GLFW的初始相关配置
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//创建窗口
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "test", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "创建窗口失败！" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//初始化配置GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW创建失败" << endl;
		return -1;
	}
	//进行渲染窗口配置
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); //定义渲染范围
	glfwSetKeyCallback(window, keycallback);

	Shader shader("vertex.vs", "fragment.frag");

	//定义顶点
	GLfloat vertexes[] = {
		 0.5f,  0.5f, 0.0f,  // Top Right
		 0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f,  0.5f, 0.0f   // Top Left 
	};
	//定义索引
	GLuint indexes[] = {
		0, 1, 3, //第一个三角形
		1, 2, 3,  //第二个三角形
		2, 3, 4
	};

	//创建VBO、VAO、EBO
	GLuint VBO, VAO, EBO;
	glGenBuffers(1, &VBO);	//这是顶点数据配置
	glGenBuffers(1, &EBO);	//这是顶点索引配置
	glGenVertexArrays(1, &VAO);

	//绑定VAO{配置VBO、EBO}解绑VAO	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	//第一个参数是顶点属性，location设置的值
	//第二个是顶点输行的大小，配置的是vec3，所以是3
	//vec数据的输行都是浮点型，这是一个emue而不是真的数据类型！
	//第四个是是否标准化
	//步长，vec3所以要用3乘，以及GLfloat才是真正的数据类型
	//最后是一个奇怪的强制类型转换，一般都是0
	glEnableVertexAttribArray(0); //同样也是location作为形参

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//刷新显示
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//渲染指令
		glClearColor(0.1f, 0.2f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//进行缓冲渲染
		//glUseProgram(shaderProgram);
		shader.Use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 4);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	cout << "窗口关闭" << endl;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();

	return 0;
}

//绘制穹顶
int drawBall()
{
	//进行GLFW的初始相关配置
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//创建窗口
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Doom", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "创建窗口失败！" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//初始化配置GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW创建失败" << endl;
		return -1;
	}
	//进行渲染窗口配置
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); //定义渲染范围
	glfwSetKeyCallback(window, keycallback);
	glfwSetScrollCallback(window, scroll_callback);

	Shader shader("vertexDoom.vs", "fragmentDoom.frag");

	//定义顶点
	//生成关键点
	GLfloat radius = 45.0f;
	GLint index = 0;
	GLfloat vertices[verticesNumber * 5];
	for (int i = 0; i <= (360 - roundDelta); i += roundDelta)
	{
		for (int j = 0; j <= (90 - doomDelta); j += doomDelta)
		{
			GLfloat doomAngle, roundAngle;
			roundAngle = i;
			doomAngle = j;
			cout << "当前处理：" << roundAngle << "," << doomAngle << "点" << endl;
			GLfloat vec[4][5] = { 0 }; //内部点，共有四个，没有计算重复绘制点  
			//-----------第一个点，左下角-----------
			//计算坐标
			vec[0][0] = radius * cosf(glm::radians(roundAngle))*cosf(glm::radians(doomAngle));
			vec[0][2] = radius * sinf(glm::radians(roundAngle))*cosf(glm::radians(doomAngle));
			vec[0][1] = radius * sinf(glm::radians(doomAngle));
			//计算贴图坐标
			GLfloat Rtex = 0.5 * ((90.0 - doomAngle)/90.0);
			GLfloat TexX, TexY;
			TexX = Rtex * sinf(glm::radians(roundAngle));
			TexY = Rtex * cosf(glm::radians(roundAngle));
			vec[0][3] = TexX + 0.5f;
			vec[0][4] = TexY + 0.5f;
			//-----------第二个点，右下角-----------
			vec[1][0] = radius * cosf(glm::radians(roundAngle + roundDelta))*cosf(glm::radians(doomAngle));
			vec[1][2] = radius * sinf(glm::radians(roundAngle + roundDelta))*cosf(glm::radians(doomAngle));
			vec[1][1] = radius * sinf(glm::radians(doomAngle));
			Rtex = 0.5 * ((90.0 - doomAngle) / 90.0);
			TexX = Rtex * sinf(glm::radians(roundAngle + roundDelta));
			TexY = Rtex * cosf(glm::radians(roundAngle + roundDelta));
			vec[1][3] = TexX + 0.5f;
			vec[1][4] = TexY + 0.5f;
			//-----------第三个点，左上角-----------
			vec[2][0] = radius * cosf(glm::radians(roundAngle))*cosf(glm::radians(doomAngle + doomDelta));
			vec[2][2] = radius * sinf(glm::radians(roundAngle))*cosf(glm::radians(doomAngle + doomDelta));
			vec[2][1] = radius * sinf(glm::radians(doomAngle + doomDelta));
			Rtex = 0.5 * ((90.0 - doomAngle - doomDelta) / 90.0);
			TexX = Rtex * sinf(glm::radians(roundAngle));
			TexY = Rtex * cosf(glm::radians(roundAngle));
			vec[2][3] = TexX + 0.5f;
			vec[2][4] = TexY + 0.5f;
			//-----------第四个点，右上角-----------
			vec[3][0] = radius * cosf(glm::radians(roundAngle + roundDelta))*cosf(glm::radians(doomAngle + doomDelta));
			vec[3][2] = radius * sinf(glm::radians(roundAngle + roundDelta))*cosf(glm::radians(doomAngle + doomDelta));
			vec[3][1] = radius * sinf(glm::radians(doomAngle + doomDelta));
			Rtex = 0.5 * ((90.0 - doomAngle - doomDelta) / 90.0);
			TexX = Rtex * sinf(glm::radians(roundAngle + roundDelta));
			TexY = Rtex * cosf(glm::radians(roundAngle + roundDelta));
			vec[3][3] = TexX + 0.5f;
			vec[3][4] = TexY + 0.5f;
			/*cout << "point 1 (x,y,z) = " << vec[0][0] << "f, " << vec[0][1] << "f, " << vec[0][2] << "f" << endl;
			cout << "point 2 (x,y,z) = " << vec[1][0] << "f, " << vec[1][1] << "f, " << vec[1][2] << "f" << endl;
			cout << "point 3 (x,y,z) = " << vec[2][0] << "f, " << vec[2][1] << "f, " << vec[2][2] << "f" << endl;*/
			//cout << "Tex (u,v) = " << vec[2][3] << "f, " << vec[2][4] << "f" << endl;
			int base = index * 30;
			//赋值操作
			for (int k = 0; k < 5; k++)
			{
				//第一个三角形，0-1-2构成
				vertices[base + k] = vec[0][k];
				vertices[base + 5 + k] = vec[1][k];
				vertices[base + 10 + k] = vec[2][k];
				//第二个三角形，1-2-3构成
				vertices[base + 15 + k] = vec[1][k];
				vertices[base + 20 + k] = vec[2][k];
				vertices[base + 25 + k] = vec[3][k];
			}
			//cout << "Check:" << vertices[base + 0] << "  ," << vertices[base + 1] << "  ," << vertices[base + 2] << endl;
			//cout << "Check:" << vertices[base + 5 + 0] << "  ," << vertices[base + 5 + 1] << "  ," << vertices[base + 5 + 2] << endl;
			//自加index
			index++;
		}
	}
	cout << "共计顶点：index = " << index << " ,申请内存 = " << verticesNumber * 5 << endl;
	
	//创建VBO、VAO、EBO
	GLuint VBO, VAO;
	glGenBuffers(1, &VBO);	//这是顶点数据配置
	glGenVertexArrays(1, &VAO);

	//绑定VAO{配置VBO、EBO}解绑VAO	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //同样也是location作为形参
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//贴图读入
	Mat skyPic = imread("D:\\show_pic\\texture\\sky.png", 1);
	GLint widthPic, heightPic;
	widthPic = skyPic.cols;
	heightPic = skyPic.rows;

	//贴图配置
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthPic, heightPic, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, skyPic.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	
	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	GLfloat viewYaw = 0.0f, viewPitch = 0.0f;

	//刷新显示
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//渲染指令
		glClearColor(0.7f, 0.2f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.Use();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);


		//进行直线平移摄像机
		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;
		glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 50.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//实现对键盘操作的响应
		GLfloat currentTime = glfwGetTime();
		GLfloat deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 3.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE) //向深度移动
			viewPitch += moveSpeed * 13.0f;
		if (keys[GLFW_KEY_S] == GL_TRUE) //向出来移动
			viewPitch -= moveSpeed * 13.0f;
		if (keys[GLFW_KEY_A] == GL_TRUE) //向左边移动
			viewYaw -= moveSpeed * 13.0f;
		if (keys[GLFW_KEY_D] == GL_TRUE) //向右边移动
			viewYaw += moveSpeed * 13.0f;
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);

		//对uniform变量赋值
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, verticesNumber);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	cout << "窗口关闭" << endl;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glfwTerminate();

	return 0;
}

//导入模型
void DrawModel() {
	//glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "MODEL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keycallback);
	glfwSetCursorPosCallback(window, mousecallback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);// 限制鼠标放在窗口内

	//glew
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, WIDTH, HEIGHT);

	//开启深度测试
	glEnable(GL_DEPTH_TEST);

	Shader shader("vertexModel.vs", "fragmentModel.frag");
	Model ourModel("E:/WORKPLACE/OpenGL/testModel.obj");

	//定义摄像机相关变量
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 60.0f);
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
	//移动的时间差
	GLfloat deltaTime = 0.0f;
	GLfloat currentTime = 0.0f;
	GLfloat lastTime = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.7f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Use();
		//进行直线平移摄像机
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(60.0f), (GLfloat)(800.0f / 600.0f), 0.1f, 200.0f);
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -8.0f));
		//使用鼠标操作改变摄像机角度，这里知识暂时改变欧拉角
		directionPos.y = sin(glm::radians(pitch + 180.0));
		directionPos.z = cos(glm::radians(pitch + 180.0)) * cos(glm::radians(yaw));
		directionPos.x = sin(glm::radians(yaw));
		directionPos = glm::normalize(directionPos);
		//cout << "pitch = " << pitch << endl;
		//这个view是摄像机投影矩阵
		glm::mat4 view;
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 15.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE) //向深度移动
			cameraPos += moveSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
		if (keys[GLFW_KEY_S] == GL_TRUE) //向出来移动
			cameraPos -= moveSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
		if (keys[GLFW_KEY_A] == GL_TRUE) //向左边移动
			cameraPos += moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		if (keys[GLFW_KEY_D] == GL_TRUE) //向右边移动
			cameraPos -= moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		view = glm::lookAt(cameraPos, cameraPos + directionPos, upPos);

		//对uniform变量赋值
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(shader);

		glfwSwapBuffers(window);
	}
	std::cout << "窗口关闭" << endl;
	glfwTerminate();
}

//绘制盒子
void drawBox()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, keycallback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);


	// Build and compile our shader program
	Shader ourShader("vertexBox.vs", "fragmentBox.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO


	// Load and create a texture 
	GLuint texture1;
	// ====================
	// Texture 1
	// ====================
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("D:\\show_pic\\texture\\sky.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
		
		// Activate shader
		ourShader.Use();

		// Create transformations
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, (GLfloat)glfwGetTime() * 0.2f, glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		// Pass them to the shaders
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Draw container
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

//绘制街景
int renderVista()
{
	//进行GLFW的初始相关配置
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//创建窗口
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vista", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "创建窗口失败！" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//初始化配置GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW创建失败" << endl;
		return -1;
	}
	//进行渲染窗口配置
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); //定义渲染范围
	glfwSetKeyCallback(window, keycallback);
	glfwSetScrollCallback(window, scroll_callback);

	Shader shader("vertexDoom.vs", "fragmentDoom.frag");

	//生成关键点
	int index = 0;
	//生成地面矩形部分的常数声明
	const GLint mesh_width = 600.0;
	const GLint mesh_height = 800.0;
	const GLint delta_x = 300, delta_y = 400;
	//生成弧形向上部分的常数
	const GLint curve_z = 300;  //也就是说向上的过程最多延申300mm
	const GLint delta_z = 20;
	//计算顶点个数
	const GLint vistaVertexNum_mesh = (mesh_width / delta_x)*(mesh_height / delta_y);
	const GLint vistaVertexNum_curve = (mesh_width / delta_x)*(curve_z / delta_z);
	const GLint vistaVertexNum = (vistaVertexNum_mesh + vistaVertexNum_curve) * 6;  //6是每个顶点会引申出一个矩形，绘制一个矩形需要6顶点
	GLfloat vertices[vistaVertexNum * 5];  //5表示一个点包含了xyz Texu Texv 5个信息
	cout << "地面矩形顶点：" << vistaVertexNum_mesh * 6 << "， 弧形顶点：" << vistaVertexNum_curve * 6 << endl;
	cout << "共产生顶点：" << vistaVertexNum << "个\n申请内存：" << vistaVertexNum * 5 << endl;
	
	//-----生成地面矩形顶点的部分-----
	for (int x = -mesh_width / 2; x <= mesh_width / 2 - delta_x; x += delta_x)
	{
		for (int y = -mesh_height/2; y <= mesh_height/2 - delta_y; y += delta_y)
		{
			GLfloat vec[4][5] = { 0 }; //内部点，共有四个，没有计算重复绘制点  
			//-----------第一个点，左下角-----------
			//计算坐标
			vec[0][0] = x;
			vec[0][2] = y;
			vec[0][1] = 0;
			//计算贴图坐标
			vec[0][3] = (x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[0][4] = (y + mesh_height / 2)/ (GLfloat)mesh_height;
			//-----------第二个点，右下角-----------
			vec[1][0] = x + delta_x;
			vec[1][2] = y;
			vec[1][1] = 0;
			vec[1][3] = (x + delta_x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[1][4] = (y + mesh_height / 2) / (GLfloat)mesh_height;
			//-----------第三个点，左上角-----------
			vec[2][0] = x;
			vec[2][2] = y + delta_y;
			vec[2][1] = 0;
			vec[2][3] = (x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[2][4] = (y + delta_y + mesh_height / 2) / (GLfloat)mesh_height;
			//-----------第四个点，右上角-----------
			vec[3][0] = x + delta_x;
			vec[3][2] = y + delta_y;
			vec[3][1] = 0;
			vec[3][3] = (x + delta_x + mesh_width / 2) / (GLfloat)mesh_width;;
			vec[3][4] = (y + delta_y + mesh_height / 2) / (GLfloat)mesh_height;
			
			int base = index * 30;
			//cout << base + 25 + 4 << " is max index " << endl;
			//赋值操作
			for (int k = 0; k < 5; k++)
			{
				//第一个三角形，0-1-2构成
				vertices[base + k] = vec[0][k];
				vertices[base + 5 + k] = vec[1][k];
				vertices[base + 10 + k] = vec[2][k];
				//第二个三角形，1-2-3构成
				vertices[base + 15 + k] = vec[1][k];
				vertices[base + 20 + k] = vec[2][k];
				vertices[base + 25 + k] = vec[3][k];
			}
			//自加index
			index++;
		}
	}

	//-----生成弧形顶点的部分-----
	GLint start_z = mesh_height / 2;  //弧形绘制是接着这个地方的z值继续绘制的
	for (int x = -mesh_width / 2; x <= mesh_width / 2 - delta_x; x += delta_x)
	{
		for (int z = 0; z <= curve_z - delta_z; z += delta_z)
		{
			GLfloat vec[4][5] = { 0 }; //内部点，共有四个，没有计算重复绘制点
			GLfloat y = (1 / 150.0) * z * z;
			//-----------第一个点，左下角-----------
			//计算坐标
			vec[0][0] = x;
			vec[0][1] = y;
			vec[0][2] = z + start_z;
			//计算贴图坐标
			vec[0][3] = (x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[0][4] = (y + mesh_height / 2) / (GLfloat)mesh_height;
			//-----------第二个点，右下角-----------
			vec[1][0] = x + delta_x;
			vec[1][1] = y;
			vec[1][2] = z + start_z;
			vec[1][3] = (x + delta_x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[1][4] = (y + mesh_height / 2) / (GLfloat)mesh_height;

			y = (1 / 150.0) * (z + delta_z) * (z + delta_z); // 需要重新计算一次y的值，因为有所改变
			//-----------第三个点，左上角-----------
			vec[2][0] = x;
			vec[2][1] = y;
			vec[2][2] = z + start_z + delta_z;
			vec[2][3] = (x + mesh_width / 2) / (GLfloat)mesh_width;
			vec[2][4] = (y + delta_y + mesh_height / 2) / (GLfloat)mesh_height;
			//-----------第四个点，右上角-----------
			vec[3][0] = x + delta_x;
			vec[3][1] = y;
			vec[3][2] = z + start_z + delta_z;
			vec[3][3] = (x + delta_x + mesh_width / 2) / (GLfloat)mesh_width;;
			vec[3][4] = (y + delta_y + mesh_height / 2) / (GLfloat)mesh_height;

			int base = index * 30;
			//赋值操作
			for (int k = 0; k < 5; k++)
			{
				//第一个三角形，0-1-2构成
				vertices[base + k] = vec[0][k];
				vertices[base + 5 + k] = vec[1][k];
				vertices[base + 10 + k] = vec[2][k];
				//第二个三角形，1-2-3构成
				vertices[base + 15 + k] = vec[1][k];
				vertices[base + 20 + k] = vec[2][k];
				vertices[base + 25 + k] = vec[3][k];
			}
			//自加index
			index++;
		}
	}
	cout << "共计顶点：index = " << index << " ,申请内存 = " << vistaVertexNum * 5 << endl;

	/*GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};*/

	//创建VBO、VAO、EBO
	GLuint VBO, VAO;
	glGenBuffers(1, &VBO);	//这是顶点数据配置
	glGenVertexArrays(1, &VAO);

	//绑定VAO{配置VBO、EBO}解绑VAO	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //同样也是location作为形参
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//贴图读入
	Mat skyPic = imread("D:\\show_pic\\cali1.jpg", 1);
	GLint widthPic, heightPic;
	widthPic = skyPic.cols;
	heightPic = skyPic.rows;

	//贴图配置
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthPic, heightPic, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, skyPic.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraPos = glm::vec3(0.0f, 200.0f, -2.0f);
	GLfloat viewYaw = 90.0f, viewPitch = 0.0f, camera_z = -2.0f;


	//刷新显示
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//渲染指令
		glClearColor(0.7f, 0.2f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.Use();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);


		//进行直线平移摄像机
		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;
		glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 1200.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//实现对键盘操作的响应
		GLfloat currentTime = glfwGetTime();
		GLfloat deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 3.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE) 
			viewPitch += moveSpeed * 13.0f;
		if (keys[GLFW_KEY_S] == GL_TRUE)
			viewPitch -= moveSpeed * 13.0f;
		if (keys[GLFW_KEY_A] == GL_TRUE)
			viewYaw -= moveSpeed * 13.0f;
		if (keys[GLFW_KEY_D] == GL_TRUE)
			viewYaw += moveSpeed * 13.0f;
		if (keys[GLFW_KEY_E] == GL_TRUE) //向前移动
			camera_z += moveSpeed * 60.0f;
		if (keys[GLFW_KEY_Q] == GL_TRUE) //向后移动
			camera_z -= moveSpeed * 60.0f;
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		cameraPos = glm::vec3(0.0f, 200.0f, camera_z);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);

		//对uniform变量赋值
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, vistaVertexNum);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	cout << "窗口关闭" << endl;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glfwTerminate();

	return 0;
}