# include "GL_support.h"

//----------ͼ�����ʱ��3D���꣬�Ǿ���pythonԤ������Ľ��(yolo)-----------------
//++++++++ �����Ӧ��ש�ϵ� ++++++++++++++
////====================== = vehicle ==========================
//int vehicle_position[][2] = {{-33, -935}, { -32, -936 }, { -32, -922 }, { -33, -911 }, { -33, -916 }, { -31, -912 }, { -34, -911 }, { -32, -895 }, { -26, -840 }, { -26, -834 }, { -27, -842 },
//{ -28, -832 }, { -34, -808 }, { -35, -806 }, { -34, -799 }, { -37, -784 }, { -32, -758 }, { -28, -742 }, { -32, -685 }, { -26, -673 }, { -29, -653 },
//{ -19, -637 }, { -18, -570 }, { -11, -561 }, { -6, -546 }, { -2, -501 }, { 1, -484 }, { 15, -473 }, { 27, -450 }, { 36, -424 }, { 39, -378 },
//{ 12, -400 }, { 31, -369 }, { 46, -362 }, { 61, -354 }, { 81, -339 }, { 91, -321 }, { 107, -303 }, { 128, -279 }, { 151, -225 }, { 139, -271 },
//{ 160, -245 }, { 175, -223 }, { 0, 0 }, { 164, -250 }, { 187, -214 }, { 200, -198 }, { 210, -177 }, { 228, -172 }, { 230, -152 }, { 332, -175 },
//{ 230, -133 }, { 256, -93 }, { 257, -73 }, { 263, -62 }, { 280, -55 }, { 285, -40 }, { 289, -22 }, { 296, -16 }, { 302, 4 }, { 307, 11 },
//{ 307, 16 }, { 306, 13 }, { 302, 9 }, { 304, -4 }, { 298, -19 }, { 297, -25 }, { 292, -35 }, { 286, -39 }, { 285, -48 }, { 284, -44 },
//{ 284, -47 }, { 284, -44 }, { 284, -47 }, { 118, -917 }, { 119, -925 }, { 121, -927 }, { 114, -929 }, { 119, -927 }, { 117, -917 }, { 118, -917 },
//{ 117, -919 }, { 119, -918 }, { 115, -906 }, { 118, -905 }, { 106, -816 }, { 111, -830 }, { 111, -825 }, { 104, -796 }, { 103, -788 }, { 91, -735 },
//{ 103, -725 }, { 115, -731 }, { 109, -699 }, { 122, -658 }, { 133, -623 }, { 134, -584 }, { 142, -589 }, { 152, -547 }, { 166, -531 }, { 181, -538 },
//{ 190, -511 }, { 188, -516 }, { 185, -512 }, { 182, -509 }, { 183, -506 }, { 196, -496 }, { 207, -481 }, { 218, -463 }, { 244, -537 }, { 271, -510 },
//{ 284, -522 }, { 295, -408 }, { 305, -398 }, { 308, -383 }, { 310, -371 }, { 328, -371 }, { 328, -361 }, { 340, -308 }, { 344, -412 }, { 339, -325 },
//{ 404, -429 }, { 359, -351 }, { 378, -343 }, { 372, -320 }, { 432, -320 }, { 419, -295 }, { 400, -251 }, { 416, -245 }, { 431, -241 }, { 440, -210 },
//{ 448, -205 }, { 438, -192 }, { 483, -171 }, { 504, -162 }, { 506, -136 }, { 509, -120 }, { 517, -111 }, { 523, -96 }, { 539, -98 }, { 514, -96 },
//{ 509, -90 }, { 492, -79 }, { 485, -56 }, { 490, -34 }, { 480, -12 }, { 486, 13 }, { 491, 41 }, { 499, 47 }, { 499, 47 }, { 498, 47 },
//{ 505, 49 }, { 502, 49 }, { 498, 47 }, { 25, -807 }, { 24, -818 }, { 27, -793 }, { 22, -790 }, { 21, -794 }, { 22, -812 }, { 21, -810 },
//{ 20, -806 }, { 21, -803 }, { 21, -795 }, { 21, -809 }, { 22, -788 }, { 25, -770 }, { 26, -771 }, { 27, -772 }, { 27, -768 }, { 23, -733 },
//{ 12, -712 }, { 0, -707 }, { -6, -651 }, { -14, -621 }, { -20, -593 }, { -41, -580 }, { -52, -537 }, { 0, 0 }, { -67, -446 }, { -72, -423 },
//{ -75, -393 }, { -81, -392 }, { -91, -385 }, { -113, -374 }, { -120, -356 }, { -138, -342 }, { -154, -321 }, { -170, -301 }, { -184, -275 }, { -223, -298 },
//{ -254, -304 }, { -265, -309 }, { -260, -311 }, { -257, -311 }, { -259, -292 }, { -256, -207 }, { -330, -226 }, { -286, -167 }, { -293, -135 }, { -301, -113 },
//{ -301, -91 }, { -303, -84 }, { -308, -67 }, { -310, -52 }, { -313, -30 }, { -305, -25 }, { -307, -10 }, { -305, 7 }, { -304, 44 }, { -310, 72 },
//{ -303, 91 }, { -304, 131 }, { -309, 143 }, { -313, 159 }, { -314, 171 }, { -314, 189 }, { -315, 217 }, { -323, 246 }, { -325, 273 }, { -334, 286 },
//{ -335, 298 }, { -334, 298 }, { -335, 297 }, { -59, -405 }, { -61, -404 }, { -61, -403 }, { -60, -401 }, { -61, -405 }, { -61, -404 }, { -60, -402 },
//{ -60, -396 }, { -58, -403 }, { -58, -403 }, { -58, -402 }, { -60, -404 }, { -61, -407 }, { -63, -418 }, { -65, -412 }, { -65, -443 }, { -69, -442 },
//{ -74, -453 }, { -78, -466 }, { -76, -470 }, { -81, -473 }, { -82, -481 }, { -82, -481 }, { -88, -507 }, { -94, -507 }, { -95, -513 }, { -100, -554 },
//{ -103, -570 }, { -103, -570 }, { -106, -577 }, { -107, -588 }, { -107, -586 }, { -109, -602 }, { -117, -624 }, { -124, -661 }, { -133, -687 }, { -132, -688 },
//{ -135, -697 }, { -136, -701 }, { -137, -697 }, { -136, -697 }, { -135, -693 }, { -135, -690 }, { -134, -686 }, { -132, -679 }, { -127, -662 }, { -122, -667 },
//{ -126, -688 }, { -120, -669 }, { -130, -704 }, { -135, -707 }, { -15, -347 }, { -17, -353 }, { -17, -348 }, { -15, -346 }, { -16, -344 }, { -18, -343 },
//{ -18, -343 }, { -16, -344 }, { -19, -376 }, { -34, -377 }, { -43, -393 }, { -61, -422 }, { -70, -437 }, { -74, -443 }, { -82, -450 }, { -98, -484 },
//{ -100, -482 }, { -90, -480 }, { -78, -467 }, { -79, -510 }, { -94, -522 }, { -111, -538 }, { -128, -564 }, { -139, -578 }, { -155, -589 }, { -169, -593 },
//{ -172, -584 }, { -168, -605 }, { -168, -649 }, { -155, -641 }, { -141, -652 }, { -97, -690 }, { -85, -700 }, { -53, -699 }, { -35, -694 }, { -15, -730 },
//{ 3, -737 }, { 7, -762 }, { 11, -740 }, { 15, -768 }, { 40, -806 }, { 42, -800 }, { 47, -806 }, { 46, -762 }, { 53, -781 }, { 65, -788 },
//{ 76, -805 }, { 90, -801 }, { 107, -851 }, { 104, -850 }, { 102, -817 }, { 107, -852 }, { 109, -860 }, { 112, -834 }, { 113, -830 }, { 117, -846 },
//{ 140, -940 }, { 140, -945 }, { 128, -933 }, { 126, -926 }, { 125, -950 }, { 131, -945 }, { 146, -977 }, { 121, -978 }, { 114, -1016 }, { 118, -1003 },
//{ 120, -1013 }, { 123, -1031 }, { 117, -1046 }, { 119, -1046 }, { 119, -1051 }, { 116, -1052 }, { 115, -1056 }, { 115, -1049 }, { 115, -1061 }, { 116, -1062 },
//{ 115, -1057 } };
////====================== = person ==========================
//int person_position[][2] = { {-283, 394}, { -284, 394 }, { -288, 394 }, { -283, 394 }, { -282, 393 }, { -282, 393 }, { -283, 393 }, { -283, 394 }, { -284, 395 }, { -284, 395 }, { -284, 394 },
//{ -281, 396 }, { -283, 394 }, { -279, 394 }, { -284, 395 }, { -284, 395 }, { -283, 394 }, { -283, 394 }, { -284, 395 }, { -284, 394 }, { -288, 394 },
//{ -283, 394 }, { -283, 394 }, { -284, 395 }, { -287, 393 }, { -283, 395 }, { -280, 395 }, { -287, 393 }, { -284, 395 }, { -283, 394 }, { -284, 395 },
//{ -287, 393 }, { -288, 395 }, { -281, 395 }, { -280, 395 }, { -283, 394 }, { -284, 395 }, { -284, 395 }, { -287, 394 }, { -284, 395 }, { -280, 395 },
//{ -284, 395 }, { -287, 393 }, { -283, 394 }, { -283, 394 }, { -284, 394 }, { -288, 394 }, { -287, 393 }, { -283, 394 }, { -284, 395 }, { -280, 395 },
//{ -285, 395 }, { -283, 394 }, { -284, 395 }, { -289, 395 }, { -284, 396 }, { -288, 394 }, { -281, 396 }, { -285, 395 }, { -283, 394 }, { -283, 394 },
//{ -280, 395 }, { -284, 395 }, { -280, 395 }, { -284, 394 }, { -287, 394 }, { -288, 394 }, { -284, 395 }, { -283, 394 }, { -283, 394 }, { -288, 394 },
//{ -287, 393 }, { -283, 394 }, { -283, 393 }, { -283, 393 }, { -280, 395 }, { -285, 396 }, { -288, 394 }, { -280, 395 }, { -284, 395 }, { -283, 394 },
//{ -287, 393 }, { -283, 394 }, { -287, 393 }, { -282, 393 }, { -287, 393 }, { -283, 394 }, { -282, 392 }, { -283, 394 }, { -284, 395 }, { -287, 394 },
//{ -286, 392 }, { -283, 393 }, { -280, 394 }, { -283, 394 }, { -283, 394 }, { -283, 394 }, { -286, 393 }, { -283, 394 }, { -284, 396 }, { -280, 395 },
//{ -287, 393 }, { -284, 394 }, { -280, 395 }, { -288, 394 }, { -288, 394 }, { -283, 394 }, { -283, 394 }, { -284, 394 }, { -281, 396 }, { -284, 394 },
//{ -284, 394 }, { -284, 395 }, { -285, 396 }, { -280, 395 }, { -288, 394 }, { -287, 393 }, { -283, 394 }, { -283, 394 }, { -283, 394 }, { -283, 394 },
//{ -287, 394 }, { -284, 395 }, { -282, 393 }, { -283, 393 }, { -283, 394 }, { -284, 395 }, { -283, 394 }, { -284, 394 }, { -245, 473 }, { -284, 395 },
//{ -283, 394 }, { -284, 395 }, { -282, 393 }, { -282, 393 }, { -283, 394 }, { -283, 394 }, { -282, 393 }, { -286, 393 }, { -284, 394 }, { -284, 394 },
//{ -284, 394 }, { -284, 394 }, { -283, 394 }, { -284, 394 }, { -280, 394 }, { -282, 392 }, { -283, 394 }, { -285, 391 }, { -284, 394 }, { -283, 393 },
//{ -279, 394 }, { -287, 394 }, { -286, 393 }, { -284, 385 }, { -258, 473 }, { -258, 473 }, { -256, 475 }, { -252, 476 }, { -251, 475 }, { -251, 476 },
//{ -248, 473 }, { -228, 471 }, { -215, 481 }, { -220, 422 }, { -219, 392 }, { -253, 290 }, { -200, 395 }, { -188, 394 }, { -177, 391 }, { -159, 392 },
//{ -148, 397 }, { -135, 392 }, { -125, 400 }, { -111, 402 }, { -98, 405 }, { -85, 403 }, { -69, 395 }, { -63, 395 }, { -48, 392 }, { -41, 388 },
//{ -32, 385 }, { -18, 380 }, { -11, 379 }, { 6, 373 }, { 17, 370 }, { 25, 364 }, { 33, 356 }, { 42, 349 }, { 43, 344 }, { 47, 346 },
//{ 54, 342 }, { 59, 343 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 },
//{ 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 },
//{ 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 }, { 62, 345 },
//{ 62, 345 }, { 62, 344 }, { 62, 345 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
//{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { -368, 479 }, { -311, 505 }, { -308, 471 }, { -290, 464 }, { -271, 469 },
//{ -251, 461 }, { -233, 448 }, { -216, 439 }, { -232, 335 }, { -176, 420 }, { -161, 420 }, { -142, 397 }, { -132, 389 }, { -123, 385 }, { -120, 379 },
//{ -109, 371 }, { -102, 367 }, { -98, 354 }, { -97, 348 }, { -85, 340 }, { -68, 324 }, { -52, 315 }, { -36, 303 }, { -20, 293 }, { 0, 283 },
//{ 16, 278 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
//{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 120, 564 }, { 120, 564 }, { 119, 562 }, { 119, 562 }, { 120, 564 }, { 119, 563 },
//{ 119, 563 }, { 119, 562 }, { 118, 540 }, { 124, 528 }, { 137, 507 }, { 150, 496 }, { 163, 480 }, { 174, 480 }, { 184, 476 }, { 188, 445 },
//{ 199, 441 }, { 182, 421 }, { 178, 414 }, { 175, 409 }, { 202, 374 }, { 140, 435 }, { 222, 362 }, { 232, 353 }, { 234, 320 }, { 260, 313 },
//{ 303, 298 }, { 274, 238 }, { 349, 264 }, { 60, 523 }, { 109, 442 }, { 123, 401 }, { 140, 362 }, { 131, 369 }, { 129, 353 }, { 103, 380 },
//{ 74, 404 }, { 64, 385 }, { 93, 351 }, { 61, 357 }, { 261, 116 }, { 209, 174 }, { -148, 576 }, { 20, 386 }, { 716, -395 }, { 58, 342 },
//{ 380, -17 }, { -39, 440 }, { 36, 358 }, { 101, 274 }, { 124, 252 }, { 132, 230 }, { 143, 224 }, { 153, 216 }, { 158, 196 }, { 161, 182 },
//{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
//{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
//{ 0, 0 }, };

// ++++++ �����Ӧ��ģ���·�� ++++++++++++++
//int vehicle_position[][2] = { {434, -574}, {398, -73}, {878, -73}, {401, -415}, {607, -1383}, {338, -443} };
int person_position[][2] = { {-332, -54}, {-211, 536}, {-211, 533}, {-202, 559}, {-106, -753}, {-104, -737}};

// ++++++++�����Ӧ���������޺�Ĳ���ͼƬ�������Ӧ��2020_10_26�ļ���ͼƬ+++++++++
int vehicle_position[][2] = { {-300, -374}, {398, -73}, {878, -73}, {401, -415}, {607, -1383}, {338, -443} };


//----------��ͨ����------------
GLint source_image_cols;
GLint source_image_rows;

//----------�����ؼ������-----------
GLfloat car_size = 170.0f; //�����ӵĸ߶ȣ�Ҳ�ǳ������һ��
GLboolean keys[1024];
double last_x, last_y, deltaX = 0, deltaY = 0;
bool first_mouse_in = true;
GLfloat pitch = 0.0f, yaw = 0.0f, aspect = 80.0f; //���һ����������ӽ�

//===========����Ԫ�صĿ��Ʊ�������=================
//��opencv�У����Ƴ��ĵ����С���������Ҫ��OpenCV�ǱߵĶ�Ӧ��
const GLint opencv_width = 3000;
const GLint opencv_height = 3000;
//���ɵ�����β��ֵĳ�������
const GLint mesh_width = 1500.0;
const GLint mesh_height = 1500.0;
const GLint delta_x = 100, delta_z = 100;
//���ɻ������ϲ��ֵĳ���
const GLint curve_len = 400;  //Ҳ����˵���ϵĹ����������300mm
const GLint delta_curve = 50;// 50;
//����mesh�Ķ������
const GLint vistaVertexNum_curve_L = (mesh_height / delta_z)*(curve_len / delta_curve);
const GLint vistaVertexNum_curve_F = (mesh_width / delta_x)*(curve_len / delta_curve);
const GLint vistaVertexNum = (1 + vistaVertexNum_curve_F * 2 + vistaVertexNum_curve_L * 2) * 6;  //6��ÿ������������һ�����Σ�
//����ת�Ǵ�����ز���
const GLint delta_theta = 30;
const GLint verticesNum_corner = (curve_len / delta_curve)*(90 / delta_theta) * 6 * 4; //��4����Ϊ��4���ս�

//============���嶥��Ԫ�ص�ȫ�ֱ���================
GLfloat vertices_box[36 * 6];
GLfloat vertices[vistaVertexNum * 6];  //6��ʾһ���������xyz index Texu Texv 6����Ϣ
GLfloat vertices_corner[verticesNum_corner * 8];  //3*���� 2*��ͼ*2�� 1��ʾ�ս�index

/*---------------------------------------�ص�����---------------------------------------*/
void GL_keycallback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
	{
		std::cout << "�û������˳���" << endl;
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

void GL_mousecallback(GLFWwindow * window, double x, double y)
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
}

void GL_scroll_callback(GLFWwindow *window, double x_offset, double y_offset)
{
	if (aspect < 1.0f)
		aspect = 1.0f;
	else if (aspect > 90.0f)
		aspect = 90.0f;
	else
		aspect -= y_offset;
	cout << "angle is:" << aspect << endl;
}

/*---------------------------------------�����Ӻ���---------------------------------------*/
static GLfloat curve_function(GLfloat x)
{
	return (1 / 350.0) * x * x;
}

static GLFWwindow* GL_creatWindow()
{
	//����GLFW�ĳ�ʼ�������
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//��������
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Vista", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "��������ʧ�ܣ�" << endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	//��ʼ������GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW����ʧ��" << endl;
	}
	//������Ⱦ��������
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height); //������Ⱦ��Χ
	glfwSetKeyCallback(window, GL_keycallback);
	glfwSetScrollCallback(window, GL_scroll_callback);

	return window;
}

static void GL_generate_car_point()
{
	GLfloat box[] = {
		-car_size, 0, -car_size,  0.0f, 0.0f,
		 car_size, 0, -car_size,  1.0f, 0.0f,
		 car_size,  car_size, -car_size,  1.0f, 1.0f,
		 car_size,  car_size, -car_size,  1.0f, 1.0f,
		-car_size,  car_size, -car_size,  0.0f, 1.0f,
		-car_size, 0, -car_size,  0.0f, 0.0f,

		-car_size, 0,  car_size,  0.0f, 0.0f,
		 car_size, 0,  car_size,  1.0f, 0.0f,
		 car_size,  car_size,  car_size,  1.0f, 1.0f,
		 car_size,  car_size,  car_size,  1.0f, 1.0f,
		-car_size,  car_size,  car_size,  0.0f, 1.0f,
		-car_size, 0,  car_size,  0.0f, 0.0f,

		-car_size,  car_size,  car_size,  1.0f, 0.0f,
		-car_size,  car_size, -car_size,  1.0f, 1.0f,
		-car_size, 0, -car_size,  0.0f, 1.0f,
		-car_size, 0, -car_size,  0.0f, 1.0f,
		-car_size, 0,  car_size,  0.0f, 0.0f,
		-car_size,  car_size,  car_size,  1.0f, 0.0f,

		 car_size,  car_size,  car_size,  1.0f, 0.0f,
		 car_size,  car_size, -car_size,  1.0f, 1.0f,
		 car_size, 0, -car_size,  0.0f, 1.0f,
		 car_size, 0, -car_size,  0.0f, 1.0f,
		 car_size, 0,  car_size,  0.0f, 0.0f,
		 car_size,  car_size,  car_size,  1.0f, 0.0f,

		-car_size, 0, -car_size,  0.0f, 1.0f,
		 car_size, 0, -car_size,  1.0f, 1.0f,
		 car_size, 0,  car_size,  1.0f, 0.0f,
		 car_size, 0,  car_size,  1.0f, 0.0f,
		-car_size, 0,  car_size,  0.0f, 0.0f,
		-car_size, 0, -car_size,  0.0f, 1.0f,

		-car_size,  car_size, -car_size,  0.0f, 1.0f,
		 car_size,  car_size, -car_size,  1.0f, 1.0f,
		 car_size,  car_size,  car_size,  1.0f, 0.0f,
		 car_size,  car_size,  car_size,  1.0f, 0.0f,
		-car_size,  car_size,  car_size,  0.0f, 0.0f,
		-car_size,  car_size, -car_size,  0.0f, 1.0f
	};
	for (int i = 0; i < 36 * 6; i++)
		vertices_box[i] = box[i];
}

static void GL_generate_curve_point()
{
	cout << "������б�洦������" << endl;
	cout << "\t������ê�㣺" << (1 + vistaVertexNum_curve_F * 2 + vistaVertexNum_curve_L * 2) << endl;
	cout << "\t���������ƶ��㣺" << vistaVertexNum << "��\n\t�����ڴ棺" << vistaVertexNum * 6 << endl;
	//���ɹؼ���
	GLint index = 0;

	//-----���ɵ�����ζ���Ĳ��֣�ֻ����6��ê�㣬����һ��������-----
	{
		GLfloat x_bias, y_bias;
		GLfloat vec[4][5] = { 0 }; //�ڲ��㣬�����ĸ���û�м����ظ����Ƶ�  
		//��Ϊ��������ʱ���Ǻ�opencv�����ͼ�ĵ���һ�£�opencv��1200*1400�ĵ���
		x_bias = (opencv_width - mesh_width) / (GLfloat)opencv_width / 2.0;
		y_bias = (opencv_height - mesh_height) / (GLfloat)opencv_height / 2.0;
		//-----------��һ���㣬���½�-----------
		//��������
		vec[0][0] = -mesh_width / 2;
		vec[0][2] = -mesh_height / 2;
		vec[0][1] = 0;
		//������ͼ����
		vec[0][3] = 1.0f - x_bias; //����opencv��x���෴��������һ���������
		vec[0][4] = y_bias;
		//-----------�ڶ����㣬���½�-----------
		vec[1][0] = mesh_width / 2;
		vec[1][2] = -mesh_height / 2;
		vec[1][1] = 0;
		vec[1][3] = x_bias;
		vec[1][4] = y_bias;
		//-----------�������㣬���Ͻ�-----------
		vec[2][0] = -mesh_width / 2;
		vec[2][2] = mesh_height / 2;
		vec[2][1] = 0;
		vec[2][3] = 1.0f - x_bias;
		vec[2][4] = 1.0f - y_bias;
		//-----------���ĸ��㣬���Ͻ�-----------
		vec[3][0] = mesh_width / 2;
		vec[3][2] = mesh_height / 2;
		vec[3][1] = 0;
		vec[3][3] = x_bias;
		vec[3][4] = 1.0f - y_bias;
		for (int k = 0; k < 5; k++)
		{
			//��һ�������Σ�0-1-2����
			vertices[k] = vec[0][k];
			vertices[6 + k] = vec[1][k];
			vertices[12 + k] = vec[2][k];
			//�ڶ��������Σ�1-2-3����
			vertices[18 + k] = vec[1][k];
			vertices[24 + k] = vec[2][k];
			vertices[30 + k] = vec[3][k];
		}
		for (int k = 0; k < 6; k++)
			vertices[k * 6 + 5] = 0.0f;
		index++;
	}

	cout << "\t--���������� index(ê������) = " << index << endl;

	//-----����ǰ�����ζ���Ĳ���-----
	GLint start_z = mesh_height / 2;  //���λ����ǽ�������ط���zֵ�������Ƶ�
	for (int x = -mesh_width / 2; x <= mesh_width / 2 - delta_x; x += delta_x)
	{
		for (int z = 0; z <= curve_len - delta_curve; z += delta_curve)
		{
			GLfloat vec[4][5] = { 0 }; //�ڲ��㣬�����ĸ���û�м����ظ����Ƶ�
			GLfloat y = curve_function(z);
			//-----------��һ���㣬���½�-----------
			//��������
			vec[0][0] = x;
			vec[0][1] = y;
			vec[0][2] = z + start_z;
			/*	����һ��ע�⣬��CV��GL�����õ�����ϵ�������ǵĳ����Ų�ͬ��
				OpenGL��z��ָ��ǰ����y��ָ����գ�x��ָ�����
				OpenCV��������Ϊ������ϵ��z��ָ����գ�y��ָ��ǰ����x��ָ���ұߣ�����Ҫ���л���
				x(GL) = -x(CV); y(GL) = z(CV); z(GL) = y(CV)  */
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 0);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;

			//-----------�ڶ����㣬���½�-----------
			vec[1][0] = x + delta_x;
			vec[1][1] = y;
			vec[1][2] = z + start_z;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 0);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;

			y = curve_function(z + delta_curve);  // ��Ҫ���¼���һ��y��ֵ����Ϊ�����ı�
			//-----------�������㣬���Ͻ�-----------
			vec[2][0] = x;
			vec[2][1] = y;
			vec[2][2] = z + start_z + delta_curve;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 0);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;

			//-----------���ĸ��㣬���Ͻ�-----------
			vec[3][0] = x + delta_x;
			vec[3][1] = y;
			vec[3][2] = z + start_z + delta_curve;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 0);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;

			GLint base = index * 36;
			//��ֵ����
			for (int k = 0; k < 5; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices[base + k] = vec[0][k];
				vertices[base + 6 + k] = vec[1][k];
				vertices[base + 12 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices[base + 18 + k] = vec[1][k];
				vertices[base + 24 + k] = vec[2][k];
				vertices[base + 30 + k] = vec[3][k];
			}
			//ѭ��6�Σ�д�볣��index-1
			for (int k = 0; k < 6; k++)
				vertices[base + k * 6 + 5] = 1.0f;
			//�Լ�index
			index++;
		}
	}
	
	cout << "\t--ǰ��������� index(ê������) = " << index << endl;

	//-----������໡�ζ���----------
	GLint start_x = mesh_width / 2;
	for (int z = -mesh_height / 2; z <= mesh_height / 2 - delta_z; z += delta_z)
	{
		for (int x = 0; x <= curve_len - delta_curve; x += delta_curve)
		{
			GLfloat vec[4][5] = { 0 }; //�ڲ��㣬�����ĸ���û�м����ظ����Ƶ�
			GLfloat curve_height = curve_function(x);
			//-----------��һ���㣬���½�-----------
			//��������
			vec[0][0] = x + start_x;
			vec[0][1] = curve_height;
			vec[0][2] = z;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 1);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;

			//-----------�ڶ����㣬���½�-----------
			vec[1][0] = x + start_x;
			vec[1][1] = curve_height;
			vec[1][2] = z + delta_z;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 1);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;

			curve_height = curve_function(x + delta_curve);  // ��Ҫ���¼���һ��y��ֵ����Ϊ�����ı�
			//-----------�������㣬���Ͻ�-----------
			vec[2][0] = x + start_x + delta_curve;
			vec[2][1] = curve_height;
			vec[2][2] = z;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 1);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;

			//-----------���ĸ��㣬���Ͻ�-----------
			vec[3][0] = x + start_x + delta_curve;
			vec[3][1] = curve_height;
			vec[3][2] = z + delta_z;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 1);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;

			int base = index * 36;
			//��ֵ����
			for (int k = 0; k < 5; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices[base + k] = vec[0][k];
				vertices[base + 6 + k] = vec[1][k];
				vertices[base + 12 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices[base + 18 + k] = vec[1][k];
				vertices[base + 24 + k] = vec[2][k];
				vertices[base + 30 + k] = vec[3][k];
			}
			//ѭ��6�Σ�д�볣��index-1
			for (int k = 0; k < 6; k++)
				vertices[base + k * 6 + 5] = 2.0f;
			//�Լ�index
			index++;
		}
	}

	cout << "\t--��������� index(ê������) = " << index << endl;

	//-----���ɺ󷽻��ζ���Ĳ���-----
	start_z = -mesh_height / 2;  //���λ����ǽ�������ط���zֵ�������Ƶ�
	for (int x = -mesh_width / 2; x <= mesh_width / 2 - delta_x; x += delta_x)
	{
		for (int z = 0; z <= curve_len - delta_curve; z += delta_curve)
		{
			GLfloat vec[4][5] = { 0 }; //�ڲ��㣬�����ĸ���û�м����ظ����Ƶ�
			GLfloat y = curve_function(z);
			//-----------��һ���㣬���½�-----------
			//��������
			vec[0][0] = x;
			vec[0][1] = y;
			vec[0][2] = -z + start_z;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 2);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;

			//-----------�ڶ����㣬���½�-----------
			vec[1][0] = x + delta_x;
			vec[1][1] = y;
			vec[1][2] = -z + start_z;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 2);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;

			y = curve_function(z + delta_curve);  // ��Ҫ���¼���һ��y��ֵ����Ϊ�����ı�
			//-----------�������㣬���Ͻ�-----------
			vec[2][0] = x;
			vec[2][1] = y;
			vec[2][2] = -z + start_z - delta_curve;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 2);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;

			//-----------���ĸ��㣬���Ͻ�-----------
			vec[3][0] = x + delta_x;
			vec[3][1] = y;
			vec[3][2] = -z + start_z - delta_curve;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 2);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;

			int base = index * 36;
			//��ֵ����
			for (int k = 0; k < 5; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices[base + k] = vec[0][k];
				vertices[base + 6 + k] = vec[1][k];
				vertices[base + 12 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices[base + 18 + k] = vec[1][k];
				vertices[base + 24 + k] = vec[2][k];
				vertices[base + 30 + k] = vec[3][k];
			}
			//ѭ��6�Σ�д�볣��index-1
			for (int k = 0; k < 6; k++)
				vertices[base + k * 6 + 5] = 3.0f;
			//�Լ�index
			index++;
		}
	}

	cout << "\t--�󷽻������ index(ê������) = " << index << endl;

	//------�����Ҳ໡������-------------
	start_x = -mesh_width / 2;
	for (int z = -mesh_height / 2; z <= mesh_height / 2 - delta_z; z += delta_z)
	{
		for (int x = 0; x <= curve_len - delta_curve; x += delta_curve)
		{
			GLfloat vec[4][5] = { 0 }; //�ڲ��㣬�����ĸ���û�м����ظ����Ƶ�
			GLfloat curve_height = curve_function(x);
			//-----------��һ���㣬���½�-----------
			//��������
			vec[0][0] = -x + start_x;
			vec[0][1] = curve_height;
			vec[0][2] = z;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 3);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;

			//-----------�ڶ����㣬���½�-----------
			vec[1][0] = -x + start_x;
			vec[1][1] = curve_height;
			vec[1][2] = z + delta_z;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 3);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;

			curve_height = curve_function(x + delta_curve);
			//-----------�������㣬���Ͻ�-----------
			vec[2][0] = -x + start_x - delta_curve;
			vec[2][1] = curve_height;
			vec[2][2] = z;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 3);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;

			//-----------���ĸ��㣬���Ͻ�-----------
			vec[3][0] = -x + start_x - delta_curve;
			vec[3][1] = curve_height;
			vec[3][2] = z + delta_z;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 3);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;

			int base = index * 36;
			//��ֵ����
			for (int k = 0; k < 5; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices[base + k] = vec[0][k];
				vertices[base + 6 + k] = vec[1][k];
				vertices[base + 12 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices[base + 18 + k] = vec[1][k];
				vertices[base + 24 + k] = vec[2][k];
				vertices[base + 30 + k] = vec[3][k];
			}
			//ѭ��6�Σ�д�볣��index-1
			for (int k = 0; k < 6; k++)
				vertices[base + k * 6 + 5] = 4.0f;
			//�Լ�index
			index++;
		}
	}

	cout << "\t--�ҷ�������� index(ê������) = " << index << endl;
}

static void GL_generate_corner_point()
{
	GLint index = 0;
	cout << "������б�洦������" << endl;
	cout << "\tê������" << verticesNum_corner / 6 << endl;
	cout << "\tԤ����Ⱦ���������" << verticesNum_corner << "\n\t�����ڴ�����" << verticesNum_corner * 8 << endl;
	//������ǰ���ս�
	for (int theta = 0; theta <= 90 - delta_theta; theta += delta_theta)
	{
		for (int virtual_z = 0; virtual_z <= curve_len - delta_curve; virtual_z += delta_curve)
		{
			GLfloat vec[4][7] = { 0 };
			GLfloat virtual_y = curve_function(virtual_z); 
			GLfloat now_angle = theta + delta_theta;
			//�������½�
			vec[0][0] = virtual_z * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[0][1] = virtual_y;
			vec[0][2] = virtual_z * cos(glm::radians(now_angle)) + mesh_height / 2;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 0);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 1);
			vec[0][5] = temp_point.x / source_image_cols;
			vec[0][6] = 1 - temp_point.y / source_image_rows;
			//�������½�
			now_angle = theta;
			vec[1][0] = virtual_z * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[1][1] = virtual_y;
			vec[1][2] = virtual_z * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 0);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 1);
			vec[1][5] = temp_point.x / source_image_cols;
			vec[1][6] = 1 - temp_point.y / source_image_rows;

			virtual_y = curve_function(virtual_z + delta_curve); 
			//�������Ͻ�
			now_angle = theta + delta_theta;
			vec[2][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[2][1] = virtual_y;
			vec[2][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 0);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 1);
			vec[2][5] = temp_point.x / source_image_cols;
			vec[2][6] = 1 - temp_point.y / source_image_rows;
			//�������Ͻ�
			now_angle = theta;
			vec[3][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[3][1] = virtual_y;
			vec[3][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 0);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 1);
			vec[3][5] = temp_point.x / source_image_cols;
			vec[3][6] = 1 - temp_point.y / source_image_rows;

			int data_len = 8;
			int base = index * data_len * 6;
			//��ֵ����
			for (int k = 0; k < data_len; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices_corner[base + k] = vec[0][k];
				vertices_corner[base + data_len + k] = vec[1][k];
				vertices_corner[base + data_len * 2 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices_corner[base + data_len * 3 + k] = vec[1][k];
				vertices_corner[base + data_len * 4 + k] = vec[2][k];
				vertices_corner[base + data_len * 5 + k] = vec[3][k];
			}
			//��ֵindex
			for (int anchor_index = 0; anchor_index < 6; anchor_index++)
				vertices_corner[base + anchor_index * data_len + (data_len - 1)] = 0.0f;
			index++;
		}
	}

	//������󷽹ս�
	for (int theta = 90; theta <= 180 - delta_theta; theta += delta_theta)
	{
		for (int virtual_z = 0; virtual_z <= curve_len - delta_curve; virtual_z += delta_curve)
		{
			GLfloat vec[4][7] = { 0 };
			GLfloat virtual_y = curve_function(virtual_z);
			GLfloat now_angle = theta + delta_theta;
			//�������½�
			vec[0][0] = virtual_z * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[0][1] = virtual_y;
			vec[0][2] = virtual_z * cos(glm::radians(now_angle)) - mesh_height / 2;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 1);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 2);
			vec[0][5] = temp_point.x / source_image_cols;
			vec[0][6] = 1 - temp_point.y / source_image_rows;
			//�������½�
			now_angle = theta;
			vec[1][0] = virtual_z * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[1][1] = virtual_y;
			vec[1][2] = virtual_z * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 1);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 2);
			vec[1][5] = temp_point.x / source_image_cols;
			vec[1][6] = 1 - temp_point.y / source_image_rows;

			virtual_y = curve_function(virtual_z + delta_curve);
			//�������Ͻ�
			now_angle = theta + delta_theta;
			vec[2][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[2][1] = virtual_y;
			vec[2][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 1);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 2);
			vec[2][5] = temp_point.x / source_image_cols;
			vec[2][6] = 1 - temp_point.y / source_image_rows;
			//�������Ͻ�
			now_angle = theta;
			vec[3][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) + mesh_width / 2;
			vec[3][1] = virtual_y;
			vec[3][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 1);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 2);
			vec[3][5] = temp_point.x / source_image_cols;
			vec[3][6] = 1 - temp_point.y / source_image_rows;

			int data_len = 8;
			int base = index * data_len * 6;
			//��ֵ����
			for (int k = 0; k < data_len; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices_corner[base + k] = vec[0][k];
				vertices_corner[base + data_len + k] = vec[1][k];
				vertices_corner[base + data_len * 2 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices_corner[base + data_len * 3 + k] = vec[1][k];
				vertices_corner[base + data_len * 4 + k] = vec[2][k];
				vertices_corner[base + data_len * 5 + k] = vec[3][k];
			}
			//��ֵindex
			for (int anchor_index = 0; anchor_index < 6; anchor_index++)
				vertices_corner[base + anchor_index * data_len + (data_len - 1)] = 1.0f;
			index++;
		}
	}

	//�����Һ󷽹ս�
	for (int theta = 180; theta <= 270 - delta_theta; theta += delta_theta)
	{
		for (int virtual_z = 0; virtual_z <= curve_len - delta_curve; virtual_z += delta_curve)
		{
			GLfloat vec[4][7] = { 0 };
			GLfloat virtual_y = curve_function(virtual_z); 
			GLfloat now_angle = theta + delta_theta;
			//�������½�
			vec[0][0] = virtual_z * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[0][1] = virtual_y;
			vec[0][2] = virtual_z * cos(glm::radians(now_angle)) - mesh_height / 2;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 2);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 3);
			vec[0][5] = temp_point.x / source_image_cols;
			vec[0][6] = 1 - temp_point.y / source_image_rows;
			//�������½�
			now_angle = theta;
			vec[1][0] = virtual_z * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[1][1] = virtual_y;
			vec[1][2] = virtual_z * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 2);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 3);
			vec[1][5] = temp_point.x / source_image_cols;
			vec[1][6] = 1 - temp_point.y / source_image_rows;

			virtual_y = curve_function(virtual_z + delta_curve);
			//�������Ͻ�
			now_angle = theta + delta_theta;
			vec[2][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[2][1] = virtual_y;
			vec[2][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 2);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 3);
			vec[2][5] = temp_point.x / source_image_cols;
			vec[2][6] = 1 - temp_point.y / source_image_rows;
			//�������Ͻ�
			now_angle = theta;
			vec[3][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[3][1] = virtual_y;
			vec[3][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) - mesh_height / 2;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 2);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 3);
			vec[3][5] = temp_point.x / source_image_cols;
			vec[3][6] = 1 - temp_point.y / source_image_rows;

			int data_len = 8;
			int base = index * data_len * 6;
			//��ֵ����
			for (int k = 0; k < data_len; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices_corner[base + k] = vec[0][k];
				vertices_corner[base + data_len + k] = vec[1][k];
				vertices_corner[base + data_len * 2 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices_corner[base + data_len * 3 + k] = vec[1][k];
				vertices_corner[base + data_len * 4 + k] = vec[2][k];
				vertices_corner[base + data_len * 5 + k] = vec[3][k];
			}
			//��ֵindex
			for (int anchor_index = 0; anchor_index < 6; anchor_index++)
				vertices_corner[base + anchor_index * data_len + (data_len - 1)] = 2.0f;
			index++;
		}
	}

	//������ǰ���ս�
	for (int theta = 270; theta <= 360 - delta_theta; theta += delta_theta)
	{
		for (int virtual_z = 0; virtual_z <= curve_len - delta_curve; virtual_z += delta_curve)
		{
			GLfloat vec[4][7] = { 0 };
			GLfloat virtual_y = curve_function(virtual_z); 
			GLfloat now_angle = theta + delta_theta;
			//�������½�
			vec[0][0] = virtual_z * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[0][1] = virtual_y;
			vec[0][2] = virtual_z * cos(glm::radians(now_angle)) + mesh_height / 2;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 3);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], 0);
			vec[0][5] = temp_point.x / source_image_cols;
			vec[0][6] = 1 - temp_point.y / source_image_rows;
			//�������½�
			now_angle = theta;
			vec[1][0] = virtual_z * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[1][1] = virtual_y;
			vec[1][2] = virtual_z * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 3);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], 0);
			vec[1][5] = temp_point.x / source_image_cols;
			vec[1][6] = 1 - temp_point.y / source_image_rows;

			virtual_y = curve_function(virtual_z + delta_curve);
			//�������Ͻ�
			now_angle = theta + delta_theta;
			vec[2][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[2][1] = virtual_y;
			vec[2][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 3);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], 0);
			vec[2][5] = temp_point.x / source_image_cols;
			vec[2][6] = 1 - temp_point.y / source_image_rows;
			//�������Ͻ�
			now_angle = theta;
			vec[3][0] = (virtual_z + delta_curve) * sin(glm::radians(now_angle)) - mesh_width / 2;
			vec[3][1] = virtual_y;
			vec[3][2] = (virtual_z + delta_curve) * cos(glm::radians(now_angle)) + mesh_height / 2;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 3);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], 0);
			vec[3][5] = temp_point.x / source_image_cols;
			vec[3][6] = 1 - temp_point.y / source_image_rows;

			int data_len = 8;
			int base = index * data_len * 6;
			//cout << base + data_len * 5 + 6 << endl;
			//��ֵ����
			for (int k = 0; k < data_len; k++)
			{
				//��һ�������Σ�0-1-2����
				vertices_corner[base + k] = vec[0][k];
				vertices_corner[base + data_len + k] = vec[1][k];
				vertices_corner[base + data_len * 2 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				vertices_corner[base + data_len * 3 + k] = vec[1][k];
				vertices_corner[base + data_len * 4 + k] = vec[2][k];
				vertices_corner[base + data_len * 5 + k] = vec[3][k];
			}
			//��ֵindex
			for (int anchor_index = 0; anchor_index < 6; anchor_index++)
				vertices_corner[base + anchor_index * data_len + (data_len - 1)] = 3.0f;
			index++;
		}
	}

	cout << "\tRecheck, index = " << index << endl;
}

static void TextureBind(GLuint* texture_id, Mat img)
{
	glGenTextures(1, texture_id);
	glBindTexture(GL_TEXTURE_2D, *texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GLint widthPic = img.cols;
	GLint heightPic = img.rows;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthPic, heightPic, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

static void VAO_Bind_5(GLuint* VAO, GLuint *VBO)  //�������ڶ���������ԣ��������鲻�ṩ���β����棬��Ҫ�ֶ�����
{
	glGenBuffers(1, VBO);	//���Ƕ�����������
	glGenVertexArrays(1, VAO);
	glBindVertexArray(*VAO);//��VAO{����VBO��EBO}���VAO	
	glBindBuffer(GL_ARRAY_BUFFER, * VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_box), vertices_box, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //ͬ��Ҳ��location��Ϊ�β�
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

static void VAO_Bind_6(GLuint* VAO, GLuint* VBO)
{
	glGenBuffers(1, VBO);	//���Ƕ�����������
	glGenVertexArrays(1, VAO);
	glBindVertexArray(*VAO);//��VAO{����VBO��EBO}���VAO	
	glBindBuffer(GL_ARRAY_BUFFER, *VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //ͬ��Ҳ��location��Ϊ�β�
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

static void VAO_Bind_8(GLuint* VAO, GLuint* VBO)
{
	glGenBuffers(1, VBO);	//���Ƕ�����������
	glGenVertexArrays(1, VAO);
	glBindVertexArray(*VAO);//��VAO{����VBO��EBO}���VAO	
	glBindBuffer(GL_ARRAY_BUFFER, *VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_corner), vertices_corner, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //ͬ��Ҳ��location��Ϊ�β�
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

static void Uniform_Look_Set(Shader shader, glm::mat4 view, glm::mat4 projection, glm::mat4 model)
{
	GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
	uniformLocation = glGetUniformLocation(shader.Program, "perspective");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
	uniformLocation = glGetUniformLocation(shader.Program, "model");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
}

//======================һЩ�൱��utils�ĺ���========================
void int2str(int input, string * str)
{
	stringstream temp;
	temp << input;
	*str = temp.str();
}

void float2str(float input, string * str)
{
	stringstream temp;
	temp << input;
	*str = temp.str();
}

int str2int(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}

float str2float(string s)
{
	float num;
	stringstream ss(s);
	ss >> num;
	return num;
}

//���ƽ־�
int renderVista()
{
	//����ͼƬ����
	Mat front_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_front.jpg", 1);
	Mat left_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_left.jpg", 1);
	Mat back_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_back.jpg", 1);
	Mat right_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_right.jpg", 1);
	source_image_cols = front_img.cols;
	source_image_rows = front_img.rows;
	
	//��������
	GLFWwindow* window = GL_creatWindow();

	//��ȡShader��Ⱦ��
	Shader shader("ShaderSource/vertexDoom.vs", "ShaderSource/fragmentDoom.frag");
	Shader shader2("ShaderSource/vertexSimple.vs", "ShaderSource/fragmentSimple.frag");
	Shader shader3("ShaderSource/vertexMix.vs", "ShaderSource/fragmentMix.frag");
	Shader shader4("ShaderSource/vertexModel.vs", "ShaderSource/fragmentModel.frag");


	Model ourModel("E:/WORKPLACE/3DSurround/Models/test.obj");


	GL_generate_car_point();
	GL_generate_curve_point();
	GL_generate_corner_point();
	

	//�����й���6-item�Ķ�������
	GLuint VBO_6, VAO_6;
	VAO_Bind_6(&VAO_6, &VBO_6);

	//�����й���5-item�Ķ������ã���ʵ�����������������ʱ�����VAO���Բ���Ҫ
	/*GLuint VBO_5, VAO_5;
	VAO_Bind_5(&VAO_5, &VBO_5);*/

	//�����й���8-item�Ķ�������
	GLuint VBO_8, VAO_8;
	VAO_Bind_8(&VAO_8, &VBO_8);

	//��ͼ����
	Mat skyPic = imread("D:\\show_pic\\wood.jpg", 1);
	Mat ground = renderSheet(front_img, left_img, back_img, right_img);
	/*imshow("Gorund", ground);
	waitKey(0);*/
	GLint widthPic, heightPic;

	//��ͼ����
	GLuint texture_front, texture_ground, texture_car, texture_left, texture_back, texture_right;
	TextureBind(&texture_front, front_img);
	TextureBind(&texture_ground, ground);
	TextureBind(&texture_car, skyPic);
	TextureBind(&texture_left, left_img);
	TextureBind(&texture_back, back_img);
	TextureBind(&texture_right, right_img);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraPos = glm::vec3(0.0f, 200.0f, -200.0f);  //�����ﲻ���ã��ڳ����while(1)��ֵ
	GLfloat viewYaw = 90.0f, viewPitch = 0.0f, camera_z = -2.0f, camera_x = 0.0f, camera_y = 400.0f;


	//ˢ����ʾ
	while (!glfwWindowShouldClose(window))
	{
		
		glfwPollEvents();
		//��Ⱦָ��
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		double start_render = (double)cv::getTickCount();
		//����ֱ��ƽ�������
		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;
		glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 4500.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//ʵ�ֶԼ��̲�������Ӧ
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
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		glm::vec3 plane_dir = glm::vec3(tempX, 0, tempZ);
		plane_dir = glm::normalize(plane_dir);
		glm::vec3 camera_move = glm::vec3(0, 0, 0);
		if (keys[GLFW_KEY_UP] == GL_TRUE) //��ǰ�ƶ�
			camera_move += moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_DOWN] == GL_TRUE) //����ƶ�
			camera_move -= moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_LEFT] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_RIGHT] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_P] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 60.0f * glm::vec3(0, 1, 0);
		if (keys[GLFW_KEY_O] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 60.0f * glm::vec3(0, 1, 0);

		cameraPos += camera_move;// glm::vec3(camera_x, 210.0f, camera_z);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);

		//��ʼʹ����Ⱦ������Ⱦ����
		shader.Use();
		//ʹ����ͼ��Ⱦ������������ͼid
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_ground);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture3"), 3);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture4"), 4);
		//��VAO
		glBindVertexArray(VAO_6);
		//��ֵһЩ��ά�ӽǵ���ξ���
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
		//����
		glDrawArrays(GL_TRIANGLES, 0, vistaVertexNum);
		glBindVertexArray(0);

		////�������������
		//shader2.Use();
		////ʹ����ͼ��Ⱦ������������ͼid
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture_car);
		//glUniform1i(glGetUniformLocation(shader2.Program, "ourTexture"), 0);
		////��ֵһЩ��ά�ӽǵ���ξ���
		//uniformLocation = glGetUniformLocation(shader2.Program, "view");
		//glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		//uniformLocation = glGetUniformLocation(shader2.Program, "perspective");
		//glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		//uniformLocation = glGetUniformLocation(shader2.Program, "model");
		//glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));

		//glBindVertexArray(VAO_5);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		//glBindVertexArray(0);

		//���ƽ��Ჿ��
		shader3.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture3"), 3);

		//��ֵһЩ��ά�ӽǵ���ξ���
		uniformLocation = glGetUniformLocation(shader3.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader3.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader3.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO_8);
		glDrawArrays(GL_TRIANGLES, 0, verticesNum_corner);
		glBindVertexArray(0);

		//��ֵһЩ��ά�ӽǵ���ξ���
		shader4.Use();
		model = glm::scale(model, glm::vec3(2.3f, 2.3f, 2.3f));
		model = glm::translate(model, glm::vec3(10.0f, 65.0f, -15.0f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		uniformLocation = glGetUniformLocation(shader4.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader4.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader4.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(shader4);

		glfwSwapBuffers(window);

		double time_render = (double)cv::getTickCount();
		cout << "3-��Ⱦʱ�䣺" << (time_render - start_render) / cv::getTickFrequency() << endl;
	}
	cout << "���ڹر�" << endl;
	glfwTerminate();

	return 0;
}

//����ģ��
void DrawModel() {
	//glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "MODEL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, GL_keycallback);
	glfwSetCursorPosCallback(window, GL_mousecallback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);// ���������ڴ�����

	//glew
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//������Ȳ���
	glEnable(GL_DEPTH_TEST);

	Shader shader("vertexModel.vs", "fragmentModel.frag");
	Model ourModel("E:/WORKPLACE/OpenGL/testModel.obj");

	//�����������ر���
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 60.0f);
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
	//�ƶ���ʱ���
	GLfloat deltaTime = 0.0f;
	GLfloat currentTime = 0.0f;
	GLfloat lastTime = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.7f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Use();
		//����ֱ��ƽ�������
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(60.0f), (GLfloat)(800.0f / 600.0f), 0.1f, 200.0f);
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -8.0f));
		//ʹ���������ı�������Ƕȣ�����֪ʶ��ʱ�ı�ŷ����
		directionPos.y = sin(glm::radians(pitch + 180.0));
		directionPos.z = cos(glm::radians(pitch + 180.0)) * cos(glm::radians(yaw));
		directionPos.x = sin(glm::radians(yaw));
		directionPos = glm::normalize(directionPos);
		//cout << "pitch = " << pitch << endl;
		//���view�������ͶӰ����
		glm::mat4 view;
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 15.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE) //������ƶ�
			cameraPos += moveSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
		if (keys[GLFW_KEY_S] == GL_TRUE) //������ƶ�
			cameraPos -= moveSpeed * glm::vec3(0.0f, 1.0f, 0.0f);
		if (keys[GLFW_KEY_A] == GL_TRUE) //������ƶ�
			cameraPos += moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		if (keys[GLFW_KEY_D] == GL_TRUE) //���ұ��ƶ�
			cameraPos -= moveSpeed * glm::normalize(glm::cross(upPos, directionPos));
		view = glm::lookAt(cameraPos, cameraPos + directionPos, upPos);

		//��uniform������ֵ
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(shader);

		glfwSwapBuffers(window);
	}
	std::cout << "���ڹر�" << endl;
	glfwTerminate();
}

//ʵʱ���ƽ־�
int renderVista_RealTime()
{
	//����Mat����������һ���ã���������ͼƬ����
	Mat front_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_front.jpg", 1);
	Mat left_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_left.jpg", 1);
	Mat back_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_back.jpg", 1);
	Mat right_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/1_right.jpg", 1);
	source_image_cols = front_img.cols;
	source_image_rows = front_img.rows;

	//����ͷ��ȡ������
	VideoCapture cap0(CAMERA_INDEX[0]);
	VideoCapture cap1(CAMERA_INDEX[1]);
	VideoCapture cap2(CAMERA_INDEX[2]);
	VideoCapture cap3(CAMERA_INDEX[3]);

	//��������
	GLFWwindow* window = GL_creatWindow();

	//��ȡShader��Ⱦ��
	Shader shader("ShaderSource/vertexDoom.vs", "ShaderSource/fragmentDoom.frag");
	Shader shader3("ShaderSource/vertexMix.vs", "ShaderSource/fragmentMix.frag");
	Shader shader4("ShaderSource/vertexModel.vs", "ShaderSource/fragmentModel.frag");

	Model ourModel("E:/WORKPLACE/3DSurround/Models/test.obj");

	GL_generate_curve_point();
	GL_generate_corner_point();

	//�����й���6-item�Ķ�������
	GLuint VBO_6, VAO_6;
	VAO_Bind_6(&VAO_6, &VBO_6);

	//�����й���8-item�Ķ�������
	GLuint VBO_8, VAO_8;
	VAO_Bind_8(&VAO_8, &VBO_8);

	//��ͼ����
	Mat ground = renderSheet(front_img, left_img, back_img, right_img);
	GLint ground_cols = ground.cols;
	GLint ground_rows = ground.rows;

	//��ͼ����
	GLuint texture_front, texture_ground, texture_car, texture_left, texture_back, texture_right;
	TextureBind(&texture_front, front_img);
	TextureBind(&texture_ground, ground);
	TextureBind(&texture_left, left_img);
	TextureBind(&texture_back, back_img);
	TextureBind(&texture_right, right_img);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraPos = glm::vec3(-200.0f, 300.0f, -200.0f);  //�����������ʼ��
	GLfloat viewYaw = 90.0f, viewPitch = 0.0f;
	glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);

	//ˢ����ʾ
	while (!glfwWindowShouldClose(window))
	{
		double start = (double)cv::getTickCount();
		//opencv��ȡ����
		cap0 >> front_img;
		cap1 >> left_img;
		cap2 >> back_img;
		cap3 >> right_img;
		double time_read = (double)cv::getTickCount();
		ground = renderSheet(front_img, left_img, back_img, right_img);
		double time_ground = (double)cv::getTickCount();

		//�������û���texture����
		/*TextureBind(&texture_front, front_img);
		TextureBind(&texture_ground, ground);
		TextureBind(&texture_left, left_img);
		TextureBind(&texture_back, back_img);
		TextureBind(&texture_right, right_img);*/

		glfwPollEvents();
		//��Ⱦָ��
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		//����ֱ��ƽ�������
		glm::mat4 projection, model, view;  // ����������½��ģ���Ϊ������ۼ�ЧӦ�����Ա���ÿ��ѭ����Ҫ���µ�
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 2500.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//ʵ�ֶԼ��̲�������Ӧ
		GLfloat currentTime = glfwGetTime();
		GLfloat deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 3.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE)
			viewPitch += moveSpeed * 23.0f;
		if (keys[GLFW_KEY_S] == GL_TRUE)
			viewPitch -= moveSpeed * 23.0f;
		if (keys[GLFW_KEY_A] == GL_TRUE)
			viewYaw -= moveSpeed * 23.0f;
		if (keys[GLFW_KEY_D] == GL_TRUE)
			viewYaw += moveSpeed * 23.0f;
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		glm::vec3 plane_dir = glm::vec3(tempX, 0, tempZ);
		plane_dir = glm::normalize(plane_dir);
		glm::vec3 camera_move = glm::vec3(0, 0, 0);
		if (keys[GLFW_KEY_UP] == GL_TRUE) //��ǰ�ƶ�
			camera_move += moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_DOWN] == GL_TRUE) //����ƶ�
			camera_move -= moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_LEFT] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_RIGHT] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_P] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 60.0f * glm::vec3(0, 1, 0);
		if (keys[GLFW_KEY_O] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 60.0f * glm::vec3(0, 1, 0);

		cameraPos += camera_move;// glm::vec3(camera_x, 210.0f, camera_z);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);


		//��ʼʹ����Ⱦ������Ⱦ����
		shader.Use();
		//ʹ����ͼ��Ⱦ������������ͼid
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_ground);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, ground_cols, ground.rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, ground.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, front_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, left_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, back_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture3"), 3);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, right_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture4"), 4);
		//��VAO
		glBindVertexArray(VAO_6);
		//��ֵһЩ��ά�ӽǵ���ξ���
		Uniform_Look_Set(shader, view, projection, model);
		//����
		glDrawArrays(GL_TRIANGLES, 0, vistaVertexNum);
		glBindVertexArray(0);

		//���ƽ��Ჿ��
		shader3.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture3"), 3);
		Uniform_Look_Set(shader3, view, projection, model);
		glBindVertexArray(VAO_8);
		glDrawArrays(GL_TRIANGLES, 0, verticesNum_corner);
		glBindVertexArray(0);


		//��ֵһЩ��ά�ӽǵ���ξ���
		shader4.Use();
		model = glm::scale(model, glm::vec3(2.3f, 2.3f, 2.3f));
		model = glm::translate(model, glm::vec3(10.0f, 65.0f, -15.0f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		Uniform_Look_Set(shader4, view, projection, model);
		ourModel.Draw(shader4);
		double time_render = (double)cv::getTickCount();
		glfwSwapBuffers(window);
		cout << "1-��ȡʱ�䣺" << (time_read - start) / cv::getTickFrequency() << endl;
		cout << "2-���ɵ���ʱ�䣺" << (time_ground - time_read) / cv::getTickFrequency() << endl;
		cout << "3-��Ⱦʱ�䣺" << (time_render - time_ground) / cv::getTickFrequency() << endl;
		cout << "4-��ʱ�䣺" << (time_render - start) / cv::getTickFrequency() << endl << endl;
	}
	cout << "���ڹر�" << endl;
	glfwTerminate();

	return 0;
}

//ʵʱ���ƽ־��������Ǵ�һ������ͼƬ�л�õ�
int renderVista_RealTime_FromImages()
{
	string root_folder = "E:\\WORKPLACE\\3DSurround\\pycharm\\image\\2020_10_26\\";
	string front_folder = root_folder + "front/";
	string left_folder = root_folder + "left/";
	string back_folder = root_folder + "back/";
	string right_folder = root_folder + "right/";
	
	int frame_index = 0;

	//����Mat����������һ���ã���������ͼƬ����
	string temp; int2str(frame_index, &temp);
	string img_name = "img_" + temp + ".jpg";
	Mat front_img = imread(front_folder + img_name, 1);
	Mat left_img = imread(left_folder + img_name, 1);
	Mat back_img = imread(back_folder + img_name, 1);
	Mat right_img = imread(right_folder + img_name, 1);
	source_image_cols = front_img.cols;
	source_image_rows = front_img.rows;

	//��������
	GLFWwindow* window = GL_creatWindow();

	//��ȡShader��Ⱦ��
	Shader shader("ShaderSource/vertexDoom.vs", "ShaderSource/fragmentDoom.frag");
	Shader shader3("ShaderSource/vertexMix.vs", "ShaderSource/fragmentMix.frag");
	Shader shader4("ShaderSource/vertexModel.vs", "ShaderSource/fragmentModel.frag");

	Model ourModel("E:/WORKPLACE/3DSurround/Models/test.obj");
	Model carModel("E:/WORKPLACE/3DSurround/Models/vehicle/car.obj");
	Model personModel("E:/WORKPLACE/3DSurround/Models/person/person.obj");

	GL_generate_curve_point();
	GL_generate_corner_point();

	//�����й���6-item�Ķ�������
	GLuint VBO_6, VAO_6;
	VAO_Bind_6(&VAO_6, &VBO_6);

	//�����й���8-item�Ķ�������
	GLuint VBO_8, VAO_8;
	VAO_Bind_8(&VAO_8, &VBO_8);

	//��ͼ����
	Mat ground = renderSheet(front_img, left_img, back_img, right_img);
	GLint ground_cols = ground.cols;
	GLint ground_rows = ground.rows;

	//��ͼ����
	GLuint texture_front, texture_ground, texture_car, texture_left, texture_back, texture_right;
	TextureBind(&texture_front, front_img);
	TextureBind(&texture_ground, ground);
	TextureBind(&texture_left, left_img);
	TextureBind(&texture_back, back_img);
	TextureBind(&texture_right, right_img);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraPos = glm::vec3(-780.0f, 700.0f, -1342.0f);  //�����������ʼ��
	//GLfloat viewYaw = 90.0f, viewPitch = 0.0f;
	GLfloat viewYaw = 50.0f, viewPitch = -18.0f;  //�����Ǵ����½ǹ�Ǹ���
	glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
	int last_index = frame_index;
	int vehicle_coord[3][2] = {{246,-368},{214, -142}, {-70,-402} };
	int vehicle_coord_test[2] = { 300, 300 };
	//ˢ����ʾ
	while (!glfwWindowShouldClose(window))
	{
		double start = (double)cv::getTickCount();
		
		// �Զ���һ֡
		//frame_index++;

		// �ֶ���һ֡
		if (keys[GLFW_KEY_N] == GL_TRUE)
			frame_index++;
		if (frame_index > 351)
			frame_index = 351;
		if (last_index != frame_index)
		{
			//opencv��ȡ�µ�һ֡����
			int2str(frame_index, &temp);
			string img_name = "img_" + temp + ".jpg";
			front_img = imread(front_folder + img_name, 1);
			left_img = imread(left_folder + img_name, 1);
			back_img = imread(back_folder + img_name, 1);
			right_img = imread(right_folder + img_name, 1);
			cout << front_folder + img_name << endl;  // �������һ��index������
		}
		last_index = frame_index;

		double time_read = (double)cv::getTickCount();
		ground = renderSheet(front_img, left_img, back_img, right_img);
		double time_ground = (double)cv::getTickCount();

		glfwPollEvents();
		//��Ⱦָ��
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		//����ֱ��ƽ�������
		glm::mat4 projection, model, view;  // ����������½��ģ���Ϊ������ۼ�ЧӦ�����Ա���ÿ��ѭ����Ҫ���µ�
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 5000.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//ʵ�ֶԼ��̲�������Ӧ
		GLfloat currentTime = glfwGetTime();
		GLfloat deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		GLfloat moveSpeed = 3.0f * deltaTime;
		if (keys[GLFW_KEY_W] == GL_TRUE)
			viewPitch += moveSpeed * 23.0f;
		if (keys[GLFW_KEY_S] == GL_TRUE)
			viewPitch -= moveSpeed * 23.0f;
		if (keys[GLFW_KEY_A] == GL_TRUE)
			viewYaw -= moveSpeed * 23.0f;
		if (keys[GLFW_KEY_D] == GL_TRUE)
			viewYaw += moveSpeed * 23.0f;
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		glm::vec3 plane_dir = glm::vec3(tempX, 0, tempZ);
		plane_dir = glm::normalize(plane_dir);
		glm::vec3 camera_move = glm::vec3(0, 0, 0);
		if (keys[GLFW_KEY_UP] == GL_TRUE) //��ǰ�ƶ�
			camera_move += moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_DOWN] == GL_TRUE) //����ƶ�
			camera_move -= moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_LEFT] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_RIGHT] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_P] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 60.0f * glm::vec3(0, 1, 0);
		if (keys[GLFW_KEY_O] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 60.0f * glm::vec3(0, 1, 0);

		cameraPos += camera_move;// glm::vec3(camera_x, 210.0f, camera_z);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);

		/*cout << "��ǰ�����λ��" << cameraPos.x << ',' << cameraPos.y << ',' << cameraPos.z << endl;
		cout << "��ǰ������Ƕȣ�pitch:" << viewPitch << "  yaw:" << viewYaw << endl;*/

		//��ʼʹ����Ⱦ������Ⱦ����
		shader.Use();
		//ʹ����ͼ��Ⱦ������������ͼid
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_ground);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, ground_cols, ground.rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, ground.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, front_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, left_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, back_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture3"), 3);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, source_image_cols, source_image_rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, right_img.data);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture4"), 4);
		//��VAO
		glBindVertexArray(VAO_6);
		//��ֵһЩ��ά�ӽǵ���ξ���
		Uniform_Look_Set(shader, view, projection, model);
		//����
		glDrawArrays(GL_TRIANGLES, 0, vistaVertexNum);
		glBindVertexArray(0);

		//���ƽ��Ჿ��
		shader3.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_left);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture1"), 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, texture_back);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture2"), 2);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, texture_right);
		glUniform1i(glGetUniformLocation(shader3.Program, "ourTexture3"), 3);
		Uniform_Look_Set(shader3, view, projection, model);
		glBindVertexArray(VAO_8);
		glDrawArrays(GL_TRIANGLES, 0, verticesNum_corner);
		glBindVertexArray(0);


		//��ֵһЩ��ά�ӽǵ���ξ���
		shader4.Use();
		model = glm::scale(model, glm::vec3(2.3f, 2.3f, 2.3f));
		model = glm::translate(model, glm::vec3(10.0f, 65.0f, -15.0f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		Uniform_Look_Set(shader4, view, projection, model);
		ourModel.Draw(shader4);
		double time_render = (double)cv::getTickCount();

		//// @@@@@@@@@@ ʵ�ֶԳ���λ�õ��ƶ�
		//if (keys[GLFW_KEY_I] == GL_TRUE)
		//	vehicle_coord_test[1] += 2;
		//if (keys[GLFW_KEY_K] == GL_TRUE)
		//	vehicle_coord_test[1] -= 2;
		//if (keys[GLFW_KEY_J] == GL_TRUE)
		//	vehicle_coord_test[0] -= 2;
		//if (keys[GLFW_KEY_L] == GL_TRUE)
		//	vehicle_coord_test[0] += 2;
		//if (keys[GLFW_KEY_P] == GL_TRUE)
		//	cout << "��ǰ����λ�ã�" << vehicle_coord[0] << ',' << vehicle_coord[1] << endl;
		////������������
		//shader4.Use();
		////���뵱ǰ֡�������ڵ���άλ�� ���������ȴ�Լ��200���볤100��
		////int *pos = vehicle_position[frame_index];
		//int *pos = vehicle_coord_test;
		//float GL_x = pos[0];
		//float GL_z = -pos[1]-100.0;
		//model = glm::translate(model, glm::vec3(GL_x, -65.0, GL_z));
		//model = glm::scale(model, glm::vec3(2.2f, 2.2f, 2.2f));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		//Uniform_Look_Set(shader4, view, projection, model);
		//carModel.Draw(shader4);
		//// ����λ�ò���ֹͣ�����û�в�������������Ҫ�����ע�͵�

		// ѭ��4�ΰѳ�����
		/*for (int car_idx = 0; car_idx < 3; car_idx++)
		{
			glm::mat4 in_model = model;
			shader4.Use();
			int *pos = vehicle_coord[car_idx];
			float GL_x = pos[0];
			float GL_z = -pos[1] - 100.0;
			in_model = glm::translate(in_model, glm::vec3(GL_x, -65.0, GL_z));
			in_model = glm::scale(in_model, glm::vec3(1.8f, 1.8f, 1.8f));
			in_model = glm::rotate(in_model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			Uniform_Look_Set(shader4, view, projection, in_model);
			carModel.Draw(shader4);
		}*/

		////��������
		//shader4.Use();
		//glm::mat4 person_model;
		////�����������ڵ���άλ��
		//int *pos_person = person_position[frame_index];
		//GL_x = -pos_person[0];
		//GL_z = pos_person[1];
		//person_model = glm::translate(person_model, glm::vec3(GL_x, 50.0, GL_z));
		//person_model = glm::scale(person_model, glm::vec3(2.2f, 2.2f, 2.2f));
		//person_model = glm::rotate(person_model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		//Uniform_Look_Set(shader4, view, projection, person_model);
		//personModel.Draw(shader4);

		glfwSwapBuffers(window);

		/*cout << "1-��ȡʱ�䣺" << (time_read - start) / cv::getTickFrequency() << endl;
		cout << "2-���ɵ���ʱ�䣺" << (time_ground - time_read) / cv::getTickFrequency() << endl;
		cout << "3-��Ⱦʱ�䣺" << (time_render - time_ground) / cv::getTickFrequency() << endl;
		cout << "4-��ʱ�䣺" << (time_render - start - (time_ground - time_read))*1.2 / cv::getTickFrequency() << endl << endl;*/
	}
	cout << "���ڹر�" << endl;
	glfwTerminate();

	return 0;
}


//��һ���ص�����ƽ�����ͼ����
void overlapping_Projection()
{
	//����ͼƬ����
	Mat front_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/6_right.jpg", 1);
	Mat left_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/6_left.jpg", 1);
	Mat back_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/6_back.jpg", 1);
	Mat right_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/6_right.jpg", 1);
	source_image_cols = front_img.cols;
	source_image_rows = front_img.rows;

	//��������
	GLFWwindow* window = GL_creatWindow();

	//��ȡShader��Ⱦ��
	Shader shader("ShaderSource/vertexSimple.vs", "ShaderSource/fragmentSimple.frag");

	int cam = 3; //camera_index
	int delta_x = 100;
	int delta_y = 50;
	int index = 0;
	int data_len = 5;

	GLint VertexNum = (400/ delta_x) * (500/delta_y) * 6;
	cout << "Ӧ�÷�����ڴ棺" << VertexNum * data_len << endl;
	GLfloat plate_vertices[1200];
	
	//������ǰ��ƽ��
	for (int x = -500; x > -900; x -= delta_x)
	{
		for (int y = 0; y < 500; y += delta_y)
		{
			GLfloat vec[4][5] = { 0 };
			//�������½�
			vec[0][0] = x;
			vec[0][1] = y;
			vec[0][2] = x + 1300.0;
			Point2f temp_point = ProjectPoint(-vec[0][0], vec[0][2], -vec[0][1], cam);
			vec[0][3] = temp_point.x / source_image_cols;
			vec[0][4] = 1 - temp_point.y / source_image_rows;
			//�������½�
			vec[1][0] = (x-delta_x);
			vec[1][1] = y;
			vec[1][2] = (x - delta_x)+1300;
			temp_point = ProjectPoint(-vec[1][0], vec[1][2], -vec[1][1], cam);
			vec[1][3] = temp_point.x / source_image_cols;
			vec[1][4] = 1 - temp_point.y / source_image_rows;

			//�������Ͻ�
			vec[2][0] = x;
			vec[2][1] = y + delta_y;
			vec[2][2] = x + 1300;
			temp_point = ProjectPoint(-vec[2][0], vec[2][2], -vec[2][1], cam);
			vec[2][3] = temp_point.x / source_image_cols;
			vec[2][4] = 1 - temp_point.y / source_image_rows;
			//�������Ͻ�
			vec[3][0] = (x - delta_x);
			vec[3][1] = y + delta_y;
			vec[3][2] = (x - delta_x) + 1300;
			temp_point = ProjectPoint(-vec[3][0], vec[3][2], -vec[3][1], cam);
			vec[3][3] = temp_point.x / source_image_cols;
			vec[3][4] = 1 - temp_point.y / source_image_rows;

			int base = index * data_len * 6;
			//cout << base + data_len * 5 + 6 << endl;
			//��ֵ����
			for (int k = 0; k < data_len; k++)
			{
				//��һ�������Σ�0-1-2����
				plate_vertices[base + k] = vec[0][k];
				plate_vertices[base + data_len + k] = vec[1][k];
				plate_vertices[base + data_len * 2 + k] = vec[2][k];
				//�ڶ��������Σ�1-2-3����
				plate_vertices[base + data_len * 3 + k] = vec[1][k];
				plate_vertices[base + data_len * 4 + k] = vec[2][k];
				plate_vertices[base + data_len * 5 + k] = vec[3][k];
			}
			index++;
		}
	}

	//��ͼ����
	GLuint texture_front;
	TextureBind(&texture_front, front_img);

	//�����й���5-item�Ķ������ã���ʵ�����������������ʱ�����VAO���Բ���Ҫ
	GLuint VBO_5, VAO_5;
	glGenBuffers(1, &VBO_5);	//���Ƕ�����������
	glGenVertexArrays(1, &VAO_5);
	glBindVertexArray(VAO_5);//��VAO{����VBO��EBO}���VAO	
	glBindBuffer(GL_ARRAY_BUFFER, VBO_5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(plate_vertices), plate_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); //ͬ��Ҳ��location��Ϊ�β�
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	GLfloat lastTime = 0.0f;
	glm::vec3 directionPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraPos = glm::vec3(0.0f, 200.0f, -200.0f);  //�����ﲻ���ã��ڳ����while(1)��ֵ
	GLfloat viewYaw = 90.0f, viewPitch = 0.0f, camera_z = -2.0f, camera_x = 0.0f, camera_y = 400.0f;

	//ˢ����ʾ
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//��Ⱦָ��
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		//����ֱ��ƽ�������
		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;
		glm::vec3 upPos = glm::vec3(0.0f, 1.0f, 0.0f);
		projection = glm::perspective(glm::radians(aspect), (GLfloat)(800.0f / 600.0f), 0.1f, 2500.0f);
		model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		//ʵ�ֶԼ��̲�������Ӧ
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
		GLfloat tempX, tempY, tempZ;
		tempX = cosf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		tempY = sinf(glm::radians(viewPitch));
		tempZ = sinf(glm::radians(viewYaw))*cosf(glm::radians(viewPitch));
		glm::vec3 dirPos = glm::vec3(tempX, tempY, tempZ);
		glm::vec3 plane_dir = glm::vec3(tempX, 0, tempZ);
		plane_dir = glm::normalize(plane_dir);
		glm::vec3 camera_move = glm::vec3(0, 0, 0);
		if (keys[GLFW_KEY_UP] == GL_TRUE) //��ǰ�ƶ�
			camera_move += moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_DOWN] == GL_TRUE) //����ƶ�
			camera_move -= moveSpeed * 160.0f * plane_dir;
		if (keys[GLFW_KEY_LEFT] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_RIGHT] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 160.0f * glm::cross(plane_dir, glm::vec3(0, 1, 0));
		if (keys[GLFW_KEY_P] == GL_TRUE) //�����ƶ�
			camera_move += moveSpeed * 60.0f * glm::vec3(0, 1, 0);
		if (keys[GLFW_KEY_O] == GL_TRUE) //�����ƶ�
			camera_move -= moveSpeed * 60.0f * glm::vec3(0, 1, 0);

		cameraPos += camera_move;// glm::vec3(camera_x, 210.0f, camera_z);
		view = glm::lookAt(cameraPos, cameraPos + dirPos, upPos);

		//��ʼʹ����Ⱦ������Ⱦ����
		shader.Use();
		//ʹ����ͼ��Ⱦ������������ͼid
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_front);
		glUniform1i(glGetUniformLocation(shader.Program, "ourTexture"), 0);
		//��ֵһЩ��ά�ӽǵ���ξ���
		GLuint uniformLocation = glGetUniformLocation(shader.Program, "view");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(view));
		uniformLocation = glGetUniformLocation(shader.Program, "perspective");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));
		uniformLocation = glGetUniformLocation(shader.Program, "model");
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO_5);
		glDrawArrays(GL_TRIANGLES, 0, VertexNum);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	cout << "���ڹر�" << endl;
	glfwTerminate();
}