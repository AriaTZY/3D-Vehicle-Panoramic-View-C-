#pragma once
#ifndef __CV_SUPPORT_
#define __CV_SUPPORT_

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

void CV_initMatices();
Point ProjectPoint(int x, int y, int z, int code);
void AutoRender2DSheet(Mat sheet);
Mat renderSheet(Mat frontImg, Mat leftImg, Mat backImg, Mat rightImg);

#endif // !__CV_SUPPORT_