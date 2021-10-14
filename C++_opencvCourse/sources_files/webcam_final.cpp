#include"headler.h"
//#include"color_define.h"

void getcontours(Mat imgErode, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hetrio;
	findContours(imgErode, contours, hetrio, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boungRect(contours.size());
	for (int i = 0;i != contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << "area:"<< area << endl;
		float peri = arcLength(contours[i],true);
		//float peri2 = arcLength(conPoly[i], true);
		cout <<"peri:"<< peri << endl;
		//cout << "peri2:" << peri2 << endl;
		approxPolyDP(contours[i], conPoly[i],0.02*peri,true);
		cout << "conpoly:" << conPoly[i].size() << endl;
		boungRect[i] = boundingRect(conPoly[i]);
		rectangle(img, boungRect[i].tl(), boungRect[i].br(), Scalar(99, 168, 125), 2);
		int objectCon = conPoly[i].size();
		if (area > 10)
		{
			drawContours(img, conPoly, i, Scalar(0, 0, 255), 2);
			if (conPoly[i].size() > 10)
			{
				/*int width = boungRect[i].width*/
				putText(img, "human", boungRect[i].tl(), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 0), 2);
				cout << "star point:"<<boungRect[i].tl() << endl;
				/*Point2i src[] = { boungRect[i].tl(),boungRect[i].tl()+width,boungRect[i].height,boungRect[i].br() };
				Point2f dst[] = ({ 0,0 }};
			Mat mertix = getPerspectiveTransform(src, dst);
			warpPerspective(src, dst, mertix, Size(), 1, 0, Scalar());*/
			}
		}
		
	}

}

//void getcolordetect(Mat mask, Mat img)
//{
//	Mat mask_config;
//	vector<Rect> Color_rect;
//	Scalar HSV_BLACK()
//	applyColorMap(mask,mask_config,usercolor)
//}

int main()
{
	int vmin = 0, hmin = 0, smin = 0;
	int vmax = 255, hmax = 179, smax = 255;

	int Sizemin = 1, Sizemax = 7;

	int threshold1min = 0, threshold1max = 100;
	int thershold2min = 0, thershold2max = 100;
	VideoCapture cap(0);
	Mat img, imgGray, imgBlur, imgCanny, imgDia, imgErode,kernel,imgHSV,mask;

	namedWindow("Trackbars", (640, 200));
	createTrackbar("hue min", "Trackbars", &hmin, 179);
	createTrackbar("sat min", "Trackbars", &smin, 255);
	createTrackbar("val min", "Trackbars", &vmin, 255);
	createTrackbar("hue max", "Trackbars", &hmax, 179);
	createTrackbar("sat max", "Trackbars", &hmin, 255);
	createTrackbar("val max", "Trackbars", &hmin, 255);

	namedWindow("shape_detect", (640, 480));
	createTrackbar("Blur", "shape_detect", &Sizemin, 7);
	createTrackbar("threshold 1", "shape_detect",&threshold1min,100);
	createTrackbar("thershold 2", "shape_detect",&thershold2min, 100);


	while (true)
	{
		Scalar lowwer(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		cap.read(img);
		cvtColor(img, imgGray, COLOR_BGR2GRAY);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		GaussianBlur(imgGray, imgBlur, Size(5, 5), 50, 50);
		Canny(imgBlur, imgCanny, 50, 50);
		kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDia, kernel);
		erode(imgDia, imgErode, kernel);
		inRange(imgHSV, lowwer, upper, mask);


		 getcontours(imgDia, img);
		 //getcolordetect(mask,img);

		 imshow("img", img);
		 imshow("mask", mask);
		 waitKey(1);
	}

	return 0;
}