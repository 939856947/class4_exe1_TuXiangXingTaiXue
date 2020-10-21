#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{


	cv::Mat dispMat = imread("D:\\333.jpg");
	Mat dispMat_gray;//彩色图像转化成灰度图  
	Mat disMat_erzhi;
	Mat disMat_erode;
	Mat disMat_dilate;
	Mat disMat_open;
	Mat disMat_close;
	cvtColor(dispMat, dispMat_gray, COLOR_BGR2GRAY);//转化为灰度图
	threshold(dispMat, disMat_erzhi, 100, 255, THRESH_BINARY);//二值化
	Mat kernel=getStructuringElement(MORPH_RECT, Size(5, 5));//内核

	morphologyEx(disMat_erzhi,disMat_erode,0,kernel);//腐蚀
	morphologyEx(disMat_erzhi, disMat_dilate, 1, kernel);//膨胀
	morphologyEx(disMat_erzhi, disMat_open, 2, kernel);//开运算
	morphologyEx(disMat_erzhi, disMat_close,3, kernel);//闭运算
	//imshow("src", dispMat);
	//imshow("gray", dispMat_gray);
	imshow("erzhi", disMat_erzhi);
	imshow("erode", disMat_erode);
	imshow("dilate", disMat_dilate);
	imshow("open", disMat_open);
	imshow("close", disMat_close);
	waitKey(0);
	return 0;

}