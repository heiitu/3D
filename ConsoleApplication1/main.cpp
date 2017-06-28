#include "epipolar.h"


void main()
{

	string filename = "E:\\一切为了学术\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\name.xml";

	FileStorage fs(filename, FileStorage::READ);

	if (!fs.isOpened())
	{
		cerr << "failed to open " << filename << endl;
	}

	vector<Point2f>points1;
	vector<Point2f>points2;

	// vector数据读取
	
	fs["points1"] >> points1;
	//cout << points1;
	fs["points2"] >> points2;
	//cout << points2;
	fs.release();


	// 摄像机矩阵



	// 极线
	const char* imagename1 = "E:\\一切为了学术\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\l-2003.bmp";
	const char* imagename2 = "E:\\一切为了学术\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\r-2003.bmp";

	//从文件中读入图像
	Mat Img1 = imread(imagename1);
	Mat Img2 = imread(imagename2);

	//如果读入图像失败
	if (Img1.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename1);
	}

	if (Img2.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename2);
	}

	//显示图像
	//namedWindow("image1",0);
	/*imshow("image1", Img1);
	imshow("image2", Img2);
	waitKey();*/

	//图像矫正


	
	//求极线
	DrawEpiLines(Img1, Img2, points1, points2);
	


    while (1);

}