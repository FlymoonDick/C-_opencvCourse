#include"headler.h"
////////// Draw Shapes And Text //////////////
void main()
{
	Mat img(512, 512,CV_8UC3,Scalar(255,255,255));//������ͼ��512*512,cv_8����ÿ������ֵ��0��255(2e8),UC3����3��ͨ��,ScalarA������������ͨ��(BGR)��ֵ
	//black(0,0,0) white(255,255,255)

	circle(img, Point(256, 256), 155, Scalar(0, 0, 0),FILLED);//���� Բ�� �뾶  ��ɫ ���(FILLED�����)

	rectangle(img,Point(130,226),Point(382,286),Scalar(0,255,255),3);//������   ���� ���Ͻ����� ���½����� ��ɫ ���
	rectangle(img, Rect(256, 256, 253, 256), Scalar(0, 0, 255), FILLED); //ͬ�����Խ�point��ΪRect�������÷�������һ��

	line(img, Point(130, 296), Point(382, 296), Scalar(0, 255, 125), 10);//���� ��ʼ�� �յ� ���

	putText(img, "Zyt`s WorkStation", Point(137, 262), FONT_HERSHEY_COMPLEX, 10, Scalar(0, 69, 255),5);//���� ���� ��ʼ�� ���� ���У���С�� ��ɫ ���

	imshow("image", img);
	waitKey(0);
}