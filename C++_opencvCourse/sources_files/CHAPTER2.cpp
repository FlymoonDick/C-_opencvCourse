#include"headler.h"


void main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);

	Mat imgGray,imgBlur, imgCanny, imgDia, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY); //转换图像为灰度图（转变为其他图也是这个）
	GaussianBlur(img, imgBlur, Size(7, 7), 50, 50);//高斯模糊 size为内核大小，越大越模糊

	Canny(imgBlur, imgCanny, 50, 50);//值越大滤掉的越多，可以简单理解为只有像素>所设值才是边缘？
	Mat Kernel1 = getStructuringElement(MORPH_DILATE,Size(3,3));//定义dilate内核，将在这里定义类型或者形状,可以创建一个膨胀内核，尺寸越大膨胀越多
	Mat Kernel2 = getStructuringElement(MORPH_ERODE, Size(3, 3));
	//最好只用奇数
	dilate(imgCanny, imgDia,Kernel1);//输入输出内核（膨胀）

	erode(imgDia, imgErode, Kernel2);//腐蚀

	imshow("image", imgCanny);
	imshow("img", img);
	imshow("image1", imgBlur);
	imshow("image Dilation", imgDia);
	imshow("image Erodation", imgErode);
	waitKey(0);

}