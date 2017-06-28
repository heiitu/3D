
#include <opencv2/opencv.hpp>
#include <iostream>  
#include <string>  
#include <vector>

using namespace std;
using namespace cv;

void DrawEpiLines(const Mat& img_1, const Mat& img_2, vector<Point2f>points1, vector<Point2f>points2);
void InitMat(Mat& m, double* num);