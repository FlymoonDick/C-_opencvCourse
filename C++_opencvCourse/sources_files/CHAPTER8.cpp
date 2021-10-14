#include"headler.h"

int main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;//����������
	faceCascade.load("F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\haarcascade_frontalface_default.xml");//��������ʶ��ѵ������

	if (faceCascade.empty())
	{
		cout << "load erroe \n" << "pleasr check the xml file" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);//�����������      ����ͼ��            ��Ӧ����ļ�������������������
		//���ֵΪ������������α���������� ָ����ÿ��ͼ�������ͼ���С���ٶ��ٵĲ�����      ָ��ÿ����ѡ����Ӧ���ж��ٸ��ھ�
		//��������
	for (int i = 0; i != faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
	}
	imshow("image", img);
	waitKey(0);
}