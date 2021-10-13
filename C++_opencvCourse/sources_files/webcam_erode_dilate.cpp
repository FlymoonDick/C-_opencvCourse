#include"headler.h"


void main()
{
	VideoCapture cap(0);
	Mat img;

	while (true)
	{
		cap.read(img);
		Mat imgGray, imgBlur, imgCanny,imgDia,imgErode;
		cvtColor(img, imgGray, COLOR_BGR2GRAY);
		GaussianBlur(imgGray, imgBlur, Size(7, 7), 0, 4);
		Canny(imgGray, imgCanny, 50, 50);

		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDia, kernel);
		erode(imgDia, imgErode, kernel);

		imshow("imgCanny", imgCanny);
		imshow("imgDia", imgDia);
		imshow("imErode", imgErode);
		waitKey(1);
	}
}