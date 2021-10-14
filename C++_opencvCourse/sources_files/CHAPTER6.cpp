#include"headler.h"

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
Mat imgHSV, mask;

int main()
{


	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\shapes.png";
	Mat img = imread(path);


	cvtColor(img, imgHSV, COLOR_BGR2HSV);//将图像转换为HSV

	namedWindow("Trackbars", (640, 200));
	createTrackbar("hue min", "Trackbars", &hmin, 179);//条名 创建的命名窗口 值的地址(min max)用于改变滑动值 H:色相，最大为180 、、SV:均为255
	createTrackbar("sat min", "Trackbars", &smin, 255);//创建跟踪条
	createTrackbar("val min", "Trackbars", &vmin, 255);
	createTrackbar("hue max", "Trackbars", &hmax, 179);
	createTrackbar("sat max", "Trackbars", &hmin, 255);
	createTrackbar("val max", "Trackbars", &hmin, 255);

	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);//使用范围来搜集我们所说的颜色

		imshow("img", img);
		imshow("imgHSV", imgHSV);
		imshow("imageMask", mask);
		waitKey(1);//每毫秒刷新
	}

	
	return 0;
}