#include"color_define.h"

void HSV_BLACK(int hmin,int smin ,int vmin,int hmax,int smx,int vmax)
{
	int hmin = 0;
	int smin = 0;
	int vmin = 0;
	int hmax = 180;
	int smax = 255;
	int vmax = 46;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}

void HSV_WHITE(int hmin, int smin, int vmin, int hmax, int smx, int vmax)
{
	int hmin = 0;
	int smin = 0;
	int vmin = 221;
	int hmax = 180;
	int smax = 30;
	int vmax = 255;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}

void HSV_YELLOW(int hmin, int smin, int vmin, int hmax, int smx, int vmax)
{
	int hmin = 26;
	int smin = 43;
	int vmin = 46;
	int hmax = 34;
	int smax = 255;
	int vmax = 255;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}

void HSV_RED(int hmin, int smin, int vmin, int hmax, int smx, int vmax)
{
	int hmin = 156;
	int smin = 43;
	int vmin = 46;
	int hmax = 180;
	int smax = 255;
	int vmax = 255;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}

void HSV_GREEN(int hmin, int smin, int vmin, int hmax, int smx, int vmax)
{
	int hmin = 35;
	int smin = 43;
	int vmin = 46;
	int hmax = 77;
	int smax = 255;
	int vmax = 255;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}

void HSV_BLUE(int hmin, int smin, int vmin, int hmax, int smx, int vmax)
{
	int hmin = 100;
	int smin = 43;
	int vmin = 46;
	int hmax = 124;
	int smax = 255;
	int vmax = 255;
	Scalar lowwer(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
}