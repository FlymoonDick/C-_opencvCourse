#include"headler.h"

float w = 250, h = 350;
float wj =250 ,hj = 350;

Mat matrix, imageWarp, imgWarpJ, matrixJ;
void main()
{
	string path = "F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\cards.jpg";
	Mat img = imread(path);
	
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} }; //��Ƭ������ʼλ�� Point2f(������) ����������������
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };    // ��Ƭ�յ�λ��

	Point2f srcJ[4] = { {776,110} ,{1016,82 } ,{844,356},{1114,331} };
	Point2f dstJ[4] = { {0.0f,0.0f},{wj,0.0f},{0.0f,hj},{wj,hj} };

	matrix = getPerspectiveTransform(src, dst); //����ʹ��ת���������ҵ�Ŀ��� ����������Ӧ��������������Ӧ��  
	matrixJ = getPerspectiveTransform(srcJ, dstJ);
		//getPerspectiveTransform͸�ӱ任
	warpPerspective(img, imageWarp, matrix,Size(w,h));//͸�ӱ任
	warpPerspective(img, imgWarpJ, matrixJ, Size(wj, hj));
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), 5);
		circle(img, srcJ[i], 10, Scalar(255, 0, 0), 5);
	}

	imshow("image", img);
	imshow("imageWarp", imageWarp);
	imshow("imageWarpJ", imgWarpJ);
	waitKey(0);
}