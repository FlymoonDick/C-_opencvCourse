#include"headler.h"

int main()
{
	VideoCapture cap(0);
	Mat img, imgGRAY, imgBlur, imgCanny, kernel;
	vector<Rect> faces;
	while (true)
	{
		cap.read(img);

		CascadeClassifier facecascade;
		facecascade.load("F:\\C++_Study_project\\opencv_project\\C++_opencvCourse\\C++_opencvCourse\\resource\\haarcascade_frontalface_default.xml");
		facecascade.detectMultiScale(img, faces, 1.1, 2);
		for (int i = 0; i != faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
			putText(img, "Face_detect", faces[i].tl(), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 200, 128), 2);
		}
		imshow("img", img);
		waitKey(1);
	}


	return 0;
}