#include<opencv2/imgcodecs/imgcodecs.hpp>  //ͼ�������
#include<opencv/highgui.h>                 //ͼ��gui
#include<opencv2/imgproc.hpp>              //ͼ����
#include<opencv.hpp>                       //��������

#include<iostream>
#include<vector>
#include<string>


using namespace std;
using namespace cv;


//void main()
//{
//	////////////////////////////////////////////  import images /////////////
//	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test.png";//·��
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//}



/// /////////////////////////////////   video   ///////////////////////////////
//void main()
//{
//	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true)
//	{
//		cap.read(img);
//		imshow("image", img);
//		waitKey(20);
//	}
//}



///////////////////////  webcam /////////////////////////
void main()
{
	VideoCapture cap(0);
	Mat img;
	while (true)
	{
		cap.read(img);
		imshow( "imge",img );
		waitKey(100);
	}
}

