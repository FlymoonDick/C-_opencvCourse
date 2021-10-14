#include"headler.h"

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
Mat imgHSV, mask;

int main()
{


	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\shapes.png";
	Mat img = imread(path);


	cvtColor(img, imgHSV, COLOR_BGR2HSV);//��ͼ��ת��ΪHSV

	namedWindow("Trackbars", (640, 200));
	createTrackbar("hue min", "Trackbars", &hmin, 179);//���� �������������� ֵ�ĵ�ַ(min max)���ڸı们��ֵ H:ɫ�࣬���Ϊ180 ����SV:��Ϊ255
	createTrackbar("sat min", "Trackbars", &smin, 255);//����������
	createTrackbar("val min", "Trackbars", &vmin, 255);
	createTrackbar("hue max", "Trackbars", &hmax, 179);
	createTrackbar("sat max", "Trackbars", &hmin, 255);
	createTrackbar("val max", "Trackbars", &hmin, 255);

	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);//ʹ�÷�Χ���Ѽ�������˵����ɫ

		imshow("img", img);
		imshow("imgHSV", imgHSV);
		imshow("imageMask", mask);
		waitKey(1);//ÿ����ˢ��
	}

	
	return 0;
}