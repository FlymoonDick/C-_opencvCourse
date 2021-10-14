#include"headler.h"


void getcontours(Mat imgErode,Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgErode, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundrect(contours.size());
	for (int i = 0; i != contours.size(); i++)
	{
		int area = contourArea(contours[i], true);
		cout <<"area"<<" :"<< area << endl;
		float peri = arcLength(contours[i],true);
		cout << "peri" << ":" << peri << endl;
		approxPolyDP(contours[i], conPoly[i], peri * 0.002, true);
		cout << "conpoly:" << conPoly.size() << endl;
		boundrect[i] = boundingRect(conPoly[i]);
		rectangle(img, boundrect[i].tl(), boundrect[i].br(), Scalar(0, 0, 255), 2);
		int objectType = conPoly.size();
		if (area <-150)
		{
			drawContours(img, conPoly, i, Scalar(255, 255, 0), 2);
		}

	}

}




int main()
{
	VideoCapture cap(0);
	Mat img,imgGary, imgBlur, imgCanny, imgDia, kernel, imgErode;

	while(true)
	{
		cap.read(img);
		cvtColor(img, imgGary, COLOR_BGR2GRAY);
		GaussianBlur(imgGary, imgBlur, Size(5, 5), 50, 50);
		Canny(imgBlur, imgCanny, 50, 50);
		kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDia, kernel);
		erode(imgDia, imgErode, kernel);

		getcontours(imgErode, img);

		imshow("img", img);
		waitKey(1);
	}
	return 0;
}