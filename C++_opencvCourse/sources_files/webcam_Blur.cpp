#include"headler.h"

void main()
{
	VideoCapture cap(0);
	Mat img;

	while (true)
	{
		cap.read(img);
		Mat imgGray,imgBlur,imgCanny;
		cvtColor(img, imgGray, COLOR_BGR2GRAY);
		GaussianBlur(imgGray, imgBlur, Size(7, 7), 0, 4);		
		Canny(imgGray, imgCanny, 50, 50);

		imshow("imgcanny", imgCanny);
		waitKey(1);
	}
}