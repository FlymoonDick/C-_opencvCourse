#include"headler.h"

void main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	cout << img.size() << endl;//检测图片大小
	//resize(img, imgResize,Size(640,480)); //改变图像大小至640*480
	resize(img, imgResize, Size(),0.5,0.5);//同比缩放

	Rect roi(100, 100, 300, 250); //要定义x,y的宽度和高度,此处为从100这个点向前（右）300个像素点，向下250个像素点
	imgCrop = img(roi); //定义裁剪的值，要用矩阵类型(Rect)

	imshow("image", img);
	imshow("imgResize", imgResize);
	imshow("imCrop", imgCrop);
	waitKey(0);
}
