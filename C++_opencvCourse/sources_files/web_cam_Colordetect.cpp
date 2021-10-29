#include"headler.h"

int main()
{
    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179,  smax = 255,  vmax = 255;

    VideoCapture cap(0);
    Mat img,imgHSV,mask;
    namedWindow("Trackbar");
    createTrackbar("hmin", "Trackbar", &hmin, 179);
    createTrackbar("smin", "Trackbar", &smin, 255);
    createTrackbar("vmin", "Trackbar", &vmin, 255);
    createTrackbar("hmax", "Trackbar", &hmin, 179);
    createTrackbar("smax", "Trackbar", &smin, 255);
    createTrackbar("vmax", "Trackbar", &vmin, 255);
    while (true)
    {
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);
        Scalar lowwer(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lowwer, upper, mask);
        imshow("mask", mask);
        //imshow("imgHSV", imgHSV);
        cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << ","<<endl;
        waitKey(1);
    }
    return 0;
}