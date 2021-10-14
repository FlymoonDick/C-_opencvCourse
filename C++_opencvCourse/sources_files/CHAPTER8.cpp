#include"headler.h"

int main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;//级联分类器
	faceCascade.load("F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\haarcascade_frontalface_default.xml");//加载人脸识别训练数据

	if (faceCascade.empty())
	{
		cout << "load erroe \n" << "pleasr check the xml file" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);//人脸级联检测      输入图像            对应对象的检测数向量。对象的数量
		//检测值为相邻正分类矩形被加入的数量 指定在每个图像比例下图像大小减少多少的参数。      指定每个候选矩形应该有多少个邻居
		//保留它。
	for (int i = 0; i != faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
	}
	imshow("image", img);
	waitKey(0);
}