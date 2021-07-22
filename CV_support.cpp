#include "CV_support.h"


//int boarder_ALL[][2] = { {-600, 600},{-700, 700} };  // 整体的显示范围，显示x范围，后是y范围
//int boarder_F[][2] = { {-600, 600}, {250, 700} };  //front的显示范围
//int boarder_R[][2] = { {160, 600},{-450, 450} };  // right的显示范围
//int boarder_B[][2] = { {-600, 600},{-700, -250} };  //back的显示范围
//int boarder_L[][2] = { {-600, -160},{-700, 700} };
//
//const int scale = 4;
//const int sheet_width = 1200 / scale;
//const int sheet_height = 1400 / scale;
//const int free_height = 430; //这个表示在半高内，除了不能映射到的黑色车身区域，剩下的长度为多少，主要是为了给创建部分矩阵用
//const int free_width = 450;
//
////定义三角区域融合高度
//int triangle_up_line = 250 / scale;
//int triangle_down_line = (1400 / scale - triangle_up_line);
//Mat front_mask = Mat::zeros(Size(sheet_width, 450 / scale), CV_8UC1);
//Mat left_mask = Mat::zeros(Size(430 / scale, triangle_down_line - triangle_up_line), CV_8UC1);
//Mat right_mask = Mat::zeros(Size(430 / scale, triangle_down_line - triangle_up_line), CV_8UC1);
//Mat back_mask = Mat::zeros(Size(sheet_width, 450 / scale), CV_8UC1);

int boarder_ALL[][2] = { {-1500, 1500},{-1500, 1500} };  // 整体的显示范围，显示x范围，后是y范围
int boarder_F[][2] = { {-1500, 1500}, {250, 1500} };  //front的显示范围
int boarder_R[][2] = { {160, 1500},{-1330, 1330} };  // right的显示范围
int boarder_B[][2] = { {-1500, 1500},{-1500, -250} };  //back的显示范围
int boarder_L[][2] = { {-1500, -160},{-1500, 1500} };

const int scale = 5;
const int sheet_width = 3000 / scale;
const int sheet_height = 3000 / scale;
const int free_width =  sheet_width * scale/2 - 160; //这个表示在半高内，除了不能映射到的黑色车身区域，剩下的长度为多少，主要是为了给创建部分矩阵用
const int free_height =  sheet_height * scale/2 - 250;


//定义三角区域融合高度
int triangle_up_line = 630 / scale;
int triangle_down_line = (sheet_height - triangle_up_line);
Mat front_mask = Mat::zeros(Size(sheet_width, free_height / scale), CV_8UC1);
Mat left_mask = Mat::zeros(Size(free_width / scale, triangle_down_line - triangle_up_line), CV_8UC1);
Mat right_mask = Mat::zeros(Size(free_width / scale, triangle_down_line - triangle_up_line), CV_8UC1);
Mat back_mask = Mat::zeros(Size(sheet_width, free_height / scale), CV_8UC1);


//全局变量，包括相机内参、相机外参（旋转矩阵）、畸变参数
vector<Mat> vec_intrisicMat;
vector<Mat> vec_dist;
Mat rvec(3, 1, cv::DataType<float>::type);
Mat tvec(3, 1, cv::DataType<float>::type);
Mat RT_front(3, 4, cv::DataType<float>::type);
Mat RT_left(3, 4, cv::DataType<float>::type);
Mat RT_back(3, 4, cv::DataType<float>::type);
Mat RT_right(3, 4, cv::DataType<float>::type);


//----下述两个数组是用于进行映射的-------
int CAMERA_INDEX[4] = { 3, 1, 0, 5 };
int LUT_LOCATION_INDEX[4][sheet_height][sheet_width][2];


//int main()
//{
//	CV_initMatices();
//	Mat sheet = Mat::zeros(Size(sheet_width, sheet_height), CV_8UC3);
//	renderSheet(sheet);
//	//下述程序是静态绘制+在线实时计算
//	Mat frontImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_front.jpg", 1);
//	Mat leftImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_left.jpg", 1);
//	sheet = ProjectPoint(sheet, frontImg, RT_front, boarder_F, boarder_ALL, scale, 'F');
//	sheet = ProjectPoint(sheet, leftImg, RT_left, boarder_L, boarder_ALL, scale, 'L');
//	imshow("test", sheet);
//	waitKey(0);
//	return 0;
//}


//这个函数是把世界坐标点转换为像素点的位置，除了给出xyz之外还需要给出code，0—3代表前左后右
Point ProjectPoint(int x, int y, int z, int code)
{
	//准备矩阵、参数等
	Mat mtx;  //先选择外参矩阵
	if (code == 0)
		mtx = RT_front;
	else if (code == 1)
		mtx = RT_left;
	else if (code == 2)
		mtx = RT_back;
	else
		mtx = RT_right;
	Mat pointArray = Mat::zeros(4, 1, CV_32F);
	pointArray.at<float>(0) = x;
	pointArray.at<float>(1) = y;
	pointArray.at<float>(2) = z;
	pointArray.at<float>(3) = 1.0;
	Mat lineArray = Mat::zeros(1, 1, CV_32FC3); //每行的世界坐标点存储
	//首先进行外参的转换，即旋转矩阵和平移矩阵
	Mat output = mtx * pointArray;
	lineArray.at<Point3f>(0) = Point3f(output.at<float>(0), output.at<float>(1), output.at<float>(2));
	//进行内参的映射
	vector<Point2f> imagePoints;
	fisheye::projectPoints(lineArray, imagePoints, rvec, tvec, vec_intrisicMat[code], vec_dist[code]);
	return imagePoints[0];
}

//这个是全自动的函数，包括了循环读取、循环绘制，并且会合成汽车模型的3d图
void AutoRender2DSheet(Mat sheet)
{
	int car_height = 550 / scale;  // 500高
	int car_width = 428 / scale;  // 340宽
	Mat car = imread("E:/WORKPLACE/3DSurround/pictures/car model/car2.jpg", 1);
	Mat car_mask = imread("E:/WORKPLACE/3DSurround/pictures/car model/car2_mask.jpg", 0);
	resize(car, car, Size(car_width, car_height));
	resize(car_mask, car_mask, Size(car_width, car_height));
	Mat car_ROI = sheet(Rect((430 - 44) / scale, (450 - 30) / scale, car_width, car_height));
	//如果想使用静态图片的就打开这个注释
	/*Mat frontImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_front.jpg", 1);
	Mat leftImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_left.jpg", 1);
	Mat rightImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_right.jpg", 1);
	Mat backImg = cv::imread("E:/WORKPLACE/3DSurround/pictures/joint/3_back.jpg", 1);*/

	//动态绘制
	VideoCapture cap0(CAMERA_INDEX[0]);
	VideoCapture cap1(CAMERA_INDEX[1]);
	VideoCapture cap2(CAMERA_INDEX[2]);
	VideoCapture cap3(CAMERA_INDEX[3]);
	Mat frontImg, leftImg, rightImg, backImg;
	while (1)
	{
		cap0 >> frontImg;
		cap1 >> leftImg;
		cap2 >> backImg;
		cap3 >> rightImg;
		double time_start = (double)cv::getTickCount();
		//绘制上部分的
		Mat front_zone = Mat::zeros(Size(sheet_width, 450 / scale), CV_8UC3);
		for (int v = 0; v < 450 / scale; v++)
		{
			Vec3b * sheetLine = front_zone.ptr<Vec3b>(v);
			for (int u = 0; u < sheet_width; u++)
				sheetLine[u] = frontImg.at<Vec3b>(LUT_LOCATION_INDEX[0][v][u][1], LUT_LOCATION_INDEX[0][v][u][0]);
		}
		Mat ROI = sheet(Rect(0, 0, sheet_width, 450 / scale));
		front_zone.copyTo(ROI, front_mask);
		//绘制左半部分
		Mat left_zone = Mat::zeros(Size(430 / scale, triangle_down_line - triangle_up_line), CV_8UC3);
		int height = left_zone.rows;
		for (int v = 0; v < height; v++)
		{
			Vec3b * sheetLine = left_zone.ptr<Vec3b>(v);
			for (int u = 0; u < 430 / scale; u++)
				sheetLine[u] = leftImg.at<Vec3b>(LUT_LOCATION_INDEX[1][v + triangle_up_line][u][1], LUT_LOCATION_INDEX[1][v + triangle_up_line][u][0]);
		}
		ROI = sheet(Rect(0, triangle_up_line, 430 / scale, height));
		left_zone.copyTo(ROI, left_mask);
		//绘制下半部分
		Mat back_zone = Mat::zeros(Size(sheet_width, 450 / scale), CV_8UC3);
		int start_line = (1400 - 450) / scale;
		for (int v = 0; v < 450 / scale; v++)
		{
			Vec3b * sheetLine = back_zone.ptr<Vec3b>(v);
			for (int u = 0; u < sheet_width; u++)
			{

				try {
					sheetLine[u] = backImg.at<Vec3b>(LUT_LOCATION_INDEX[2][v + start_line][u][1], LUT_LOCATION_INDEX[2][v + start_line][u][0]);
				}
				catch (exception& e)
				{
					continue;
				}
			}
		}
		ROI = sheet(Rect(0, start_line, sheet_width, 450 / scale));
		back_zone.copyTo(ROI, back_mask);
		//绘制右半部分
		Mat right_zone = Mat::zeros(Size(430 / scale, triangle_down_line - triangle_up_line), CV_8UC3);
		int start_col = (1200 - 430) / scale;
		for (int v = 0; v < height; v++)
		{
			Vec3b * sheetLine = right_zone.ptr<Vec3b>(v);
			for (int u = 0; u < 430 / scale; u++)
				sheetLine[u] = rightImg.at<Vec3b>(LUT_LOCATION_INDEX[3][v + triangle_up_line][u + start_col][1], LUT_LOCATION_INDEX[3][v + triangle_up_line][u + start_col][0]);
		}
		ROI = sheet(Rect(start_col, triangle_up_line, 430 / scale, height));
		right_zone.copyTo(ROI, right_mask);
		//绘制小汽车
		car.copyTo(car_ROI, car_mask);
		imshow("TRY", sheet);
		waitKey(50);
	}
}

//计算每一个区域的映射LUT
void CaculateZoneProjection(Mat mtx, int boarder[][2], int map[][2], int index)
{
	int width = (boarder[0][1] - boarder[0][0]) / scale;
	int height = (boarder[1][1] - boarder[1][0]) / scale;
	//进行循环构建点阵
	for (int y_index = 0; y_index < height; y_index++)
	{
		Mat lineArray = Mat::zeros(width, 1, CV_32FC3); //每行的世界坐标点存储
		for (int x_index = 0; x_index < width; x_index++)
		{
			int row = boarder[1][0] + y_index * scale;  // 计算出实际世界坐标系下的xy值
			int	col = boarder[0][0] + x_index * scale;
			Mat pointArray = Mat::zeros(4, 1, CV_32F);  //每个的世界坐标点存储，用于和旋转矩阵相乘
			pointArray.at<float>(0) = col;
			pointArray.at<float>(1) = row;
			pointArray.at<float>(3) = 1.0;
			Mat output = mtx * pointArray;
			lineArray.at<Point3f>(x_index) = Point3f(output.at<float>(0), output.at<float>(1), output.at<float>(2));
		}
		//进行点的映射，把相机坐标系下的点映射到图片上
		vector<Point2f> imagePoints;
		fisheye::projectPoints(lineArray, imagePoints, rvec, tvec, vec_intrisicMat[index], vec_dist[index]);
		//开始渲染这一行
		int render_row = (map[1][1] - boarder[1][1]) / scale + height - y_index - 1;
		for (int draw_u = 0; draw_u < width; draw_u++)
		{
			int render_col = (map[0][1] + boarder[0][0] + draw_u * scale) / scale;
			int x = imagePoints[draw_u].x;
			int y = imagePoints[draw_u].y;
			//限幅，防止索引超限
			if (x >= 640) x = 639;
			else if (x < 0) x = 0;
			if (y >= 480) x = 439;
			else if (y < 0) x = 0;
			LUT_LOCATION_INDEX[index][render_row][render_col][0] = x;
			LUT_LOCATION_INDEX[index][render_row][render_col][1] = y;
		}
	}
}

//计算LUT的数组+计算mask图片
void init_LUT()
{
	cout << "initial LUT array..." << endl;
	//======-------------计算映射坐标值-------------=========
	CaculateZoneProjection(RT_front, boarder_F, boarder_ALL, 0);
	CaculateZoneProjection(RT_back, boarder_B, boarder_ALL, 2);
	CaculateZoneProjection(RT_left, boarder_L, boarder_ALL, 1);
	CaculateZoneProjection(RT_right, boarder_R, boarder_ALL, 3);
	////======-------------计算前方bias坐标值-------------=======
	//定义mask三角形的锚点
	/*Point leftup = Point(440 / scale, 450 / scale);
	Point rightup = Point(759 / scale, 450 / scale);
	Point leftdown = Point(440 / scale, 950 / scale);
	Point rightdown = Point(760 / scale, 950 / scale);*/

	Point leftup = Point(free_width/scale, free_height/scale);
	Point rightup = Point(sheet_width - free_width/scale, free_height/scale);
	Point leftdown = Point(free_width/scale, sheet_height-free_height/scale);
	Point rightdown = Point(sheet_width - free_width/scale, sheet_height - free_height/scale);

	Point leftup_anchor = Point(0, triangle_up_line);
	Point rightup_anchor = Point(sheet_width, triangle_up_line);
	/*-------------绘制前方的mask-------------*/
	//绘制左下角的三角形
	Point root_point[1][3];
	root_point[0][0] = leftup;
	root_point[0][1] = leftup_anchor;
	root_point[0][2] = Point(0, free_height/scale);
	const Point* point_array[1] = { root_point[0] };
	int npt[] = { 3 };
	fillPoly(front_mask, point_array, npt, 1, 255);
	//绘制右下角
	root_point[0][0] = rightup;
	root_point[0][1] = rightup_anchor;
	root_point[0][2] = Point(sheet_width, free_height/scale);
	fillPoly(front_mask, point_array, npt, 1, 255);
	threshold(front_mask, front_mask, 10, 255, CV_THRESH_BINARY_INV);
	/*-------------绘制左边的mask-------------*/
	root_point[0][0] = Point(leftup.x, 0);
	root_point[0][1] = Point(leftup.x, leftup.y - triangle_up_line - 5);
	root_point[0][2] = Point(0, -5);
	fillPoly(left_mask, point_array, npt, 1, 255);

	root_point[0][0] = Point(0, triangle_down_line - triangle_up_line + 5);
	root_point[0][1] = Point(leftdown.x, triangle_down_line - triangle_up_line);
	root_point[0][2] = Point(leftdown.x, leftdown.y - triangle_up_line + 5);
	fillPoly(left_mask, point_array, npt, 1, 255);
	threshold(left_mask, left_mask, 10, 255, CV_THRESH_BINARY_INV);
	/*-------------绘制后边的mask-------------*/
	root_point[0][0] = Point(0, 0);
	root_point[0][1] = Point(0, triangle_down_line - leftdown.y);
	root_point[0][2] = Point(leftdown.x, 0);
	fillPoly(back_mask, point_array, npt, 1, 255);

	root_point[0][0] = Point(sheet_width, 0);
	root_point[0][1] = Point(sheet_width, triangle_down_line - leftdown.y);
	root_point[0][2] = Point(rightdown.x, 0);
	fillPoly(back_mask, point_array, npt, 1, 255);
	threshold(back_mask, back_mask, 10, 255, CV_THRESH_BINARY_INV);
	/*-------------绘制右边的mask-------------*/
	root_point[0][0] = Point(free_width/scale, -5); // sheet_width - rightup.x
	root_point[0][1] = Point(0, leftup.y - triangle_up_line - 5);
	root_point[0][2] = Point(0, 0);
	fillPoly(right_mask, point_array, npt, 1, 255);

	root_point[0][0] = Point(0, triangle_down_line - triangle_up_line);
	root_point[0][1] = Point(0, rightdown.y - triangle_up_line + 5);
	root_point[0][2] = Point(free_width / scale, triangle_down_line - triangle_up_line + 3);
	fillPoly(right_mask, point_array, npt, 1, 255);
	threshold(right_mask, right_mask, 10, 255, CV_THRESH_BINARY_INV);
	cout << "initial done!" << endl;
}

//最终的函数，包括旋转矩阵、内参矩阵的初始化以及上个函数的参数初始化
void CV_initMatices()
{
	Mat intrisicMat(3, 3, cv::DataType<float>::type);
	Mat dist(4, 1, cv::DataType<float>::type);
	//front内参矩阵
	intrisicMat.at<float>(0, 0) = 225.72178081263067;
	intrisicMat.at<float>(0, 1) = 0.0;
	intrisicMat.at<float>(0, 2) = 321.96633799109753;

	intrisicMat.at<float>(1, 0) = 0.0;
	intrisicMat.at<float>(1, 1) = 223.2285288966986;
	intrisicMat.at<float>(1, 2) = 246.3869556120706;

	intrisicMat.at<float>(2, 0) = 0.0;
	intrisicMat.at<float>(2, 1) = 0.0;
	intrisicMat.at<float>(2, 2) = 1.0;
	Mat front = intrisicMat.clone();
	vec_intrisicMat.push_back(front);

	dist.at<float>(0) = -0.02037657262403154;
	dist.at<float>(1) = -0.014287103171377493;
	dist.at<float>(2) = 0.025033228794991685;
	dist.at<float>(3) = -0.013057747261212267;
	Mat front_d = dist.clone();
	vec_dist.push_back(front_d);

	//left内参矩阵
	intrisicMat.at<float>(0, 0) = 218.65531794403827;
	intrisicMat.at<float>(0, 2) = 310.50121174602526;
	intrisicMat.at<float>(1, 1) = 215.39957902366683;
	intrisicMat.at<float>(1, 2) = 247.30826877876999;
	Mat left = intrisicMat.clone();
	vec_intrisicMat.push_back(left);

	dist.at<float>(0) = -0.014172403622643947;
	dist.at<float>(1) = -0.03822754173759392;
	dist.at<float>(2) = 0.034992974105021085;
	dist.at<float>(3) = -0.011792807943546112;
	Mat left_d = dist.clone();
	vec_dist.push_back(left_d);

	//back内参矩阵
	/*intrisicMat.at<float>(0, 0) = 238.87052313877663;
	intrisicMat.at<float>(0, 2) = 328.1263268763279;
	intrisicMat.at<float>(1, 1) = 236.36510731401265;
	intrisicMat.at<float>(1, 2) = 228.35450912275593;*/
	intrisicMat.at<float>(0, 0) = 230.06128303299045;
	intrisicMat.at<float>(0, 2) = 331.50734605703826;
	intrisicMat.at<float>(1, 1) = 227.7059984364518;
	intrisicMat.at<float>(1, 2) = 226.27665547531006;
	Mat back = intrisicMat.clone();
	vec_intrisicMat.push_back(back);

	/*dist.at<float>(0) = -0.03231958237996581;
	dist.at<float>(1) = -0.0022693899191978772;
	dist.at<float>(2) = 0.008768319032577323;
	dist.at<float>(3) = -0.0073711397484963566;*/
	dist.at<float>(0) = -0.05775625591664545;
	dist.at<float>(1) = 0.11557861960208955;
	dist.at<float>(2) = -0.15085191268661619;
	dist.at<float>(3) = 0.06189430906468899;
	Mat back_d = dist.clone();
	vec_dist.push_back(back_d);

	//right内参矩阵
	intrisicMat.at<float>(0, 0) = 230.49778543136196;
	intrisicMat.at<float>(0, 2) = 322.7803340235745;
	intrisicMat.at<float>(1, 1) = 228.7741891938643;
	intrisicMat.at<float>(1, 2) = 234.8824698127876;
	Mat right = intrisicMat.clone();
	vec_intrisicMat.push_back(right);

	dist.at<float>(0) = -0.043438158060804456;
	dist.at<float>(1) = 0.07565461088474043;
	dist.at<float>(2) = -0.10926042746707278;
	dist.at<float>(3) = 0.04917866814643769;
	Mat right_d = dist.clone();
	vec_dist.push_back(right_d);

	//构建旋转向量
	rvec.at<float>(0, 0) = 0.0;
	rvec.at<float>(1, 0) = 0.0;
	rvec.at<float>(2, 0) = 0;

	//构建平移向量
	tvec.at<float>(0) = 0.0;
	tvec.at<float>(1) = 0.0;
	tvec.at<float>(2) = 0.0;

	//外参矩阵-前摄像机
	RT_front.at<float>(0, 0) = -0.9940;
	RT_front.at<float>(0, 1) = 0.0224;
	RT_front.at<float>(0, 2) = 0.0345;
	RT_front.at<float>(0, 3) = 1.4697;

	RT_front.at<float>(1, 0) = -0.0156;
	RT_front.at<float>(1, 1) = 0.5618;
	RT_front.at<float>(1, 2) = -0.8291;
	RT_front.at<float>(1, 3) = -278.1589;

	RT_front.at<float>(2, 0) = -0.0383;
	RT_front.at<float>(2, 1) = -0.8333;
	RT_front.at<float>(2, 2) = -0.5581;
	RT_front.at<float>(2, 3) = 103.8625;

	//外参矩阵-右摄像机
	RT_right.at<float>(0, 0) = 0.0096;
	RT_right.at<float>(0, 1) = 0.9916;
	RT_right.at<float>(0, 2) = 0.0197;
	RT_right.at<float>(0, 3) = -2.7942;

	RT_right.at<float>(1, 0) = 0.6947;
	RT_right.at<float>(1, 1) = 0.0084;
	RT_right.at<float>(1, 2) = -0.7248;
	RT_right.at<float>(1, 3) = -248.8677;

	RT_right.at<float>(2, 0) = -0.7307;
	RT_right.at<float>(2, 1) = 0.0195;
	RT_right.at<float>(2, 2) = -0.6888;
	RT_right.at<float>(2, 3) = 19.8905;

	//外参矩阵-后摄像机
	RT_back.at<float>(0, 0) = 0.9794;
	RT_back.at<float>(0, 1) = -0.0285;
	RT_back.at<float>(0, 2) = -0.0140;
	RT_back.at<float>(0, 3) = -13.3692;

	RT_back.at<float>(1, 0) = -0.0265;
	RT_back.at<float>(1, 1) = -0.5557;
	RT_back.at<float>(1, 2) = -0.8388;
	RT_back.at<float>(1, 3) = -270.1422;

	RT_back.at<float>(2, 0) = 0.0158;
	RT_back.at<float>(2, 1) = 0.8560;
	RT_back.at<float>(2, 2) = -0.5450;
	RT_back.at<float>(2, 3) = 106.9254;

	//外参矩阵-左摄像机
	RT_left.at<float>(0, 0) = 0.0050;
	RT_left.at<float>(0, 1) = -1.0038;
	RT_left.at<float>(0, 2) = 0.0101;
	RT_left.at<float>(0, 3) = -1.0884;

	RT_left.at<float>(1, 0) = -0.6956;
	RT_left.at<float>(1, 1) = -0.0115;
	RT_left.at<float>(1, 2) = -0.7158;
	RT_left.at<float>(1, 3) = -251.6519;

	RT_left.at<float>(2, 0) = 0.7131;
	RT_left.at<float>(2, 1) = -0.0027;
	RT_left.at<float>(2, 2) = -0.6983;
	RT_left.at<float>(2, 3) = 21.4662;
	double LUT_start = (double)cv::getTickCount();
	init_LUT();
	cout << "查找表生成时间：" << ((double)cv::getTickCount() - LUT_start) / cv::getTickFrequency() << endl;
}

//这个函数是单次使用，只是用来绘制一个地面，无汽车模型，以及把图片的读取权交给外部，方便统一调用
Mat renderSheet(Mat frontImg, Mat leftImg, Mat backImg, Mat rightImg)
{
	Mat sheet = Mat::zeros(Size(sheet_width, sheet_height), CV_8UC3);
	
	double time_start = (double)cv::getTickCount();
	//绘制上部分的
	Mat front_zone = Mat::zeros(Size(sheet_width, free_height / scale), CV_8UC3);
	for (int v = 0; v < free_height / scale; v++)
	{
		Vec3b * sheetLine = front_zone.ptr<Vec3b>(v);
		for (int u = 0; u < sheet_width; u++)
			sheetLine[u] = frontImg.at<Vec3b>(LUT_LOCATION_INDEX[0][v][u][1], LUT_LOCATION_INDEX[0][v][u][0]);
	}
	Mat ROI = sheet(Rect(0, 0, sheet_width, free_height / scale));
	front_zone.copyTo(ROI, front_mask);
	//绘制左半部分
	Mat left_zone = Mat::zeros(Size(free_width / scale, triangle_down_line - triangle_up_line), CV_8UC3);
	int height = left_zone.rows;
	for (int v = 0; v < height; v++)
	{
		Vec3b * sheetLine = left_zone.ptr<Vec3b>(v);
		for (int u = 0; u < free_width / scale; u++)
			sheetLine[u] = leftImg.at<Vec3b>(LUT_LOCATION_INDEX[1][v + triangle_up_line][u][1], LUT_LOCATION_INDEX[1][v + triangle_up_line][u][0]);
	}
	ROI = sheet(Rect(0, triangle_up_line, free_width/scale, height));
	left_zone.copyTo(ROI, left_mask);
	//绘制右半部分
	Mat right_zone = Mat::zeros(Size(free_width / scale, triangle_down_line - triangle_up_line), CV_8UC3);
	int start_col = sheet_width - free_width / scale;
	for (int v = 0; v < height; v++)
	{
		Vec3b * sheetLine = right_zone.ptr<Vec3b>(v);
		for (int u = 0; u < free_width / scale; u++)
			sheetLine[u] = rightImg.at<Vec3b>(LUT_LOCATION_INDEX[3][v + triangle_up_line][u + start_col][1], LUT_LOCATION_INDEX[3][v + triangle_up_line][u + start_col][0]);
	}
	ROI = sheet(Rect(start_col, triangle_up_line, free_width / scale, height));
	right_zone.copyTo(ROI, right_mask);
	//绘制下半部分
	Mat back_zone = Mat::zeros(Size(sheet_width, free_height / scale), CV_8UC3);
	int start_line = sheet_height - free_height / scale;
	for (int v = 0; v < free_height / scale; v++)
	{
		Vec3b * sheetLine = back_zone.ptr<Vec3b>(v);
		for (int u = 0; u < sheet_width; u++)
		{
			//在下半部分的绘制过程中有超限的可能，所以使用try catch语句
			try {sheetLine[u] = backImg.at<Vec3b>(LUT_LOCATION_INDEX[2][v + start_line][u][1], LUT_LOCATION_INDEX[2][v + start_line][u][0]);}
			catch (exception& e){continue;}
		}
	}
	ROI = sheet(Rect(0, start_line, sheet_width, free_height/scale));
	back_zone.copyTo(ROI, back_mask);
	return sheet;
}

