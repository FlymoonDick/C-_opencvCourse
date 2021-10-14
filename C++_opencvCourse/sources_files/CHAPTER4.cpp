#include"headler.h"
////////// Draw Shapes And Text //////////////
void main()
{
	Mat img(512, 512,CV_8UC3,Scalar(255,255,255));//创建空图像，512*512,cv_8代表每个像素值从0到255(2e8),UC3代表3个通道,ScalarA用于设置三个通道(BGR)的值
	//black(0,0,0) white(255,255,255)

	circle(img, Point(256, 256), 155, Scalar(0, 0, 0),FILLED);//输入 圆心 半径  颜色 厚度(FILLED填充满)

	rectangle(img,Point(130,226),Point(382,286),Scalar(0,255,255),3);//画矩形   输入 左上角坐标 右下角坐标 颜色 厚度
	rectangle(img, Rect(256, 256, 253, 256), Scalar(0, 0, 255), FILLED); //同样可以将point改为Rect函数，用法与上章一样

	line(img, Point(130, 296), Point(382, 296), Scalar(0, 255, 125), 10);//输入 起始点 终点 厚度

	putText(img, "Zyt`s WorkStation", Point(137, 262), FONT_HERSHEY_COMPLEX, 10, Scalar(0, 69, 255),5);//输入 内容 起始点 字体 比列（大小） 颜色 厚度

	imshow("image", img);
	waitKey(0);
}