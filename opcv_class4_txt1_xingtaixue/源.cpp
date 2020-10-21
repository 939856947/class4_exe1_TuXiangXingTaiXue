#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{


	cv::Mat dispMat = imread("D:\\333.jpg");
	Mat dispMat_gray;//��ɫͼ��ת���ɻҶ�ͼ  
	Mat disMat_erzhi;
	Mat disMat_erode;
	Mat disMat_dilate;
	Mat disMat_open;
	Mat disMat_close;
	cvtColor(dispMat, dispMat_gray, COLOR_BGR2GRAY);//ת��Ϊ�Ҷ�ͼ
	threshold(dispMat, disMat_erzhi, 100, 255, THRESH_BINARY);//��ֵ��
	Mat kernel=getStructuringElement(MORPH_RECT, Size(5, 5));//�ں�

	morphologyEx(disMat_erzhi,disMat_erode,0,kernel);//��ʴ
	morphologyEx(disMat_erzhi, disMat_dilate, 1, kernel);//����
	morphologyEx(disMat_erzhi, disMat_open, 2, kernel);//������
	morphologyEx(disMat_erzhi, disMat_close,3, kernel);//������
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