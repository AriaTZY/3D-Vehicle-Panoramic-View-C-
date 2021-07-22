#include <iostream>

#include "GL_support.h"
//#include "CV_support.h"


int main()
{
	CV_initMatices();
	renderVista_RealTime_FromImages();
	//overlapping_Projection();
	//renderVista_RealTime();
	renderVista();
	Mat front_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/3_front.jpg", 1);
	Mat left_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/3_left.jpg", 1);
	Mat back_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/3_back.jpg", 1);
	Mat right_img = imread("E:/WORKPLACE/3DSurround/pictures/joint/3_right.jpg", 1);
	Mat ground = renderSheet(front_img, left_img, back_img, right_img);
	imshow("I dont know", ground);
	waitKey(0);
	//
	return 0;
}


