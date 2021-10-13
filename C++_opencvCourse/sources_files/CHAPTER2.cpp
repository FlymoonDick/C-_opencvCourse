#include"headler.h"


void main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);

	Mat imgGray,imgBlur, imgCanny, imgDia, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY); //ת��ͼ��Ϊ�Ҷ�ͼ��ת��Ϊ����ͼҲ�������
	GaussianBlur(img, imgBlur, Size(7, 7), 50, 50);//��˹ģ�� sizeΪ�ں˴�С��Խ��Խģ��

	Canny(imgBlur, imgCanny, 50, 50);//ֵԽ���˵���Խ�࣬���Լ����Ϊֻ������>����ֵ���Ǳ�Ե��
	Mat Kernel1 = getStructuringElement(MORPH_DILATE,Size(3,3));//����dilate�ںˣ��������ﶨ�����ͻ�����״,���Դ���һ�������ںˣ��ߴ�Խ������Խ��
	Mat Kernel2 = getStructuringElement(MORPH_ERODE, Size(3, 3));
	//���ֻ������
	dilate(imgCanny, imgDia,Kernel1);//��������ںˣ����ͣ�

	erode(imgDia, imgErode, Kernel2);//��ʴ

	imshow("image", imgCanny);
	imshow("img", img);
	imshow("image1", imgBlur);
	imshow("image Dilation", imgDia);
	imshow("image Erodation", imgErode);
	waitKey(0);

}