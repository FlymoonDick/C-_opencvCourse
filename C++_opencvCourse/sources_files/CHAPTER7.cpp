#include"headler.h"

void getcontours(Mat imgDia,Mat img) //��imgDia��Ѱ���������ڻ���img��
{ 
	//{ {Point(20,30) }, Point*50,60) //����������ʸ������������,����һ���б�ÿ����������һ������
	//	{ },   ����Ĵ������൱�������vector�������С�����ǵڶ���vector���ڶ���vector����point
	//	{ } }
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;//vec4i:��4������ֵ
	string objectType;
	findContours(imgDia, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//hierarchyΪ����ṹ��������4��������opencv���Լ�����������
	// RETR_EXTERNAL:�������е��������������κβ�ι�ϵ
	// 	 CHAIN_APPROX_SIMPLE:   ѹ��ˮƽ����ֱ�ͶԽ��߶Σ�ֻ�������ǵĶ˵㡣	���磬һ�����ϵľ�������������Ϊ4����

	//drawContours(img, contours, -1, Scalar(55, 0, 255), 2);///////   -1����ȫ����ӡ

	vector<vector<Point>> conPoly(contours.size());//�����ܳ�����������
	vector<Rect> boundRect(contours.size());//�����ܳ�����������

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);  //�����������������
		cout << area << endl;  
		if (area > 1000)  
		{
			//����ÿ�������ܳ������������������(�ǵ���)������Ϊ�����ܳ�*0.02
			float peri = arcLength(contours[i],true);//����ÿ�������ܳ� bool��ȡ���ڸö����Ƿ���--true���������Ǳպϵ�
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//approxPolyDp-��ָ���㼯���ж���αƽ�������������ָ���侫�ȣ����ĸ�����boolͬ��
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);//i���������൱����area��100����ӡ��Ӧ��i����������ȥ�����
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);//�������,boungrect�൱���������һ����������
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 255), 5);//tl:���ϣ�   br������

			int objCor = conPoly[i].size();
			
			if (objCor == 3)
			{
				objectType = "sanjiao";
			}
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;//������εĳ����
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

	//�ҵ�ͼ���Ե��canny����ʶ����Ӧ�ı�
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\shapes.png";
	Mat img = imread(path);

	Mat imgGary, imgBlur,imgCanny,imgDia,kernel;

	//preprossing
	cvtColor(img, imgGary, COLOR_BGR2GRAY);//Ԥ�����Ҷ�ͼ+��˹ģ��+canny��Ե���+����
	GaussianBlur(imgGary, imgBlur, Size(5, 5),50,50);
	Canny(imgBlur, imgCanny, 50, 50);//�����м������С�ڵ㣬�����Ҫ���ͻ�����������
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