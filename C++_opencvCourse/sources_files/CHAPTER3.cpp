#include"headler.h"

void main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	cout << img.size() << endl;//���ͼƬ��С
	//resize(img, imgResize,Size(640,480)); //�ı�ͼ���С��640*480
	resize(img, imgResize, Size(),0.5,0.5);//ͬ������

	Rect roi(100, 100, 300, 250); //Ҫ����x,y�Ŀ�Ⱥ͸߶�,�˴�Ϊ��100�������ǰ���ң�300�����ص㣬����250�����ص�
	imgCrop = img(roi); //����ü���ֵ��Ҫ�þ�������(Rect)

	imshow("image", img);
	imshow("imgResize", imgResize);
	imshow("imCrop", imgCrop);
	waitKey(0);
}
