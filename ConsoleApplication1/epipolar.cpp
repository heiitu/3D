#include"stdafx.h"
#include "epipolar.h"

void InitMat(Mat& m, double* num)
{
	for (int i = 0; i<m.rows; i++)
		for (int j = 0; j<m.cols; j++)
			m.at<float>(i, j) = *(num + i*m.rows + j);
}


void DrawEpiLines(const Mat& img_1, const Mat& img_2, vector<Point2f>points1, vector<Point2f>points2){

	
	//cv::Mat F = cv::findFundamentalMat(points1, points2, CV_FM_8POINT);
	//���ȸ��ݶ�Ӧ����������ͼ�Ļ������󣬻����������������������������ϵ
	// F����
	double F0[] = { 104600000., 373260000., -1022700000000.,
		259280000., -76690000., 2312000000000.,
		-1408600000000., -2439300000000., 1255200000000000.
	};

	Mat F(3, 3, CV_32F);
	InitMat(F, F0);
	cout << F << endl;

	vector<cv::Vec<float, 3>> epilines1, epilines2;
	cv::computeCorrespondEpilines(points1, 1, F, epilines1);//�����Ӧ����⼫��epilines��һ����Ԫ��(a,b,c)����ʾ������һ��ͼ�ж�Ӧ���⼫��ax+by+c=0;  
	cv::computeCorrespondEpilines(points2, 2, F, epilines2);
	cout << epilines1[0][0] << endl;
	cout << epilines1[0][1] << endl;
	cout << epilines1[0][2] << endl;

}