#include "epipolar.h"


void main()
{

	string filename = "E:\\һ��Ϊ��ѧ��\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\name.xml";

	FileStorage fs(filename, FileStorage::READ);

	if (!fs.isOpened())
	{
		cerr << "failed to open " << filename << endl;
	}

	vector<Point2f>points1;
	vector<Point2f>points2;

	// vector���ݶ�ȡ
	
	fs["points1"] >> points1;
	//cout << points1;
	fs["points2"] >> points2;
	//cout << points2;
	fs.release();


	// ���������



	// ����
	const char* imagename1 = "E:\\һ��Ϊ��ѧ��\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\l-2003.bmp";
	const char* imagename2 = "E:\\һ��Ϊ��ѧ��\\C++_pro\\first_step\\test\\3Dreconstruction\\Debug\\r-2003.bmp";

	//���ļ��ж���ͼ��
	Mat Img1 = imread(imagename1);
	Mat Img2 = imread(imagename2);

	//�������ͼ��ʧ��
	if (Img1.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename1);
	}

	if (Img2.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename2);
	}

	//��ʾͼ��
	//namedWindow("image1",0);
	/*imshow("image1", Img1);
	imshow("image2", Img2);
	waitKey();*/

	//ͼ�����


	
	//����
	DrawEpiLines(Img1, Img2, points1, points2);
	


    while (1);

}