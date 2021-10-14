#include"headler.h"

void getcontours(Mat imgDia,Mat img) //在imgDia上寻找轮廓，在画到img上
{ 
	//{ {Point(20,30) }, Point*50,60) //定义轮廓（矢量）在向量内,就像一个列表，每个向量将是一个轮廓
	//	{ },   外面的大括号相当于最外层vector，里面的小括号是第二层vector，第二层vector中有point
	//	{ } }
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;//vec4i:有4个整数值
	string objectType;
	findContours(imgDia, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//hierarchy为程序结构，里面有4个整数，opencv有自己的数据类型
	// RETR_EXTERNAL:检索所有的轮廓而不建立任何层次关系
	// 	 CHAIN_APPROX_SIMPLE:   压缩水平、垂直和对角线段，只留下它们的端点。	例如，一个向上的矩形轮廓被编码为4个点

	//drawContours(img, contours, -1, Scalar(55, 0, 255), 2);///////   -1就是全部打印

	vector<vector<Point>> conPoly(contours.size());//他不能超过轮廓数量
	vector<Rect> boundRect(contours.size());//他不能超过轮廓数量

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);  //测量各个轮廓的面积
		cout << area << endl;  
		if (area > 1000)  
		{
			//计算每个轮廓周长，随后估计轮廓点个数(角点检测)，精度为轮廓周长*0.02
			float peri = arcLength(contours[i],true);//计算每个轮廓周长 bool是取决于该对象是否封闭--true近似曲线是闭合的
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//approxPolyDp-对指定点集进行多边形逼近，第三个参数指定其精度，第四个曲线bool同上
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);//i是轮廓，相当于是area》100，打印相应的i轮廓常用于去除噪点
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);//包络矩形,boungrect相当于在外面的一个矩形轮廓
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 255), 5);//tl:左上，   br：右下

			int objCor = conPoly[i].size();
			
			if (objCor == 3)
			{
				objectType = "sanjiao";
			}
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;//包络矩形的长宽比
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05)
				{
					objectType = "zhengfang";
				}
				else
				objectType = "juxing";
			}
			else if (objCor > 4)
			{
				objectType = "yuan";
			}
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_COMPLEX, 1, Scalar{ 50,255,168 }, 5);
		}
	}
}

int main()
{
	//////////////////  shape detect ////////////////////////\

	//找到图像边缘（canny），识别相应的边
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\shapes.png";
	Mat img = imread(path);

	Mat imgGary, imgBlur,imgCanny,imgDia,kernel;

	//preprossing
	cvtColor(img, imgGary, COLOR_BGR2GRAY);//预处理：灰度图+高斯模糊+canny边缘检测+膨胀
	GaussianBlur(imgGary, imgBlur, Size(5, 5),50,50);
	Canny(imgBlur, imgCanny, 50, 50);//在线中间可能有小黑点，因此需要膨胀或是做闭运算
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDia, kernel);

	getcontours(imgDia,img);

	imshow("img", img);
	//imshow("imgGRAY", imgGary);
	//imshow("imBlur", imgBlur);
	//imshow("imgCanny", imgCanny);
	//imshow("imgDia", imgDia);
	waitKey(0);
	return 0;
}