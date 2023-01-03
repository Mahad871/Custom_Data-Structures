#include <opencv2/core.hpp>
#include <opencv2\cvconfig.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;



//"C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Original Images\\IMD002.bmp"

// write
//"C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp"


//void test() {
//	Scalar intensity = img.at<uchar>(i, j);
//	//Scalar intensity = img.at<uchar>(Point(i, j));
//
//	float blue = intensity.val[0];
//	/*int green = intensity.val[1];
//	int red = intensity.val[2];*/
//
//	if (intensity.val[0] != 0) {
//
//		if (isStart) {
//			si = i;
//			sj = j;
//			isStart = false;
//		}
//
//
//		//cout <<"  (" << red << "," << green << ","<<blue<<")";
//		//cout << "\n##########" << i << "########" << j;
//		//cout << " (" << blue << ") ";
//
//		//cout << img.row(i).col(j); 
//
//	}
//
//	Scalar x = img.at<uchar>(i - 8, j + 8);
//	Scalar z = img.at<uchar>(i + 8, j);
//	int v = 0;
//
//	if (z.val[0] == 255 && x.val[0] == 255 && !isTrue) {
//		isTrue = true;
//		v = 255;
//	}
//	else
//	{
//		v = 0;
//	}
//
//	if (isTrue) {
//
//		img.row(i).col(j) = v;
//	}
//
//
//
//	isTrue = false;
//}

bool isHorConnected(Mat img, int r, int c) {

	int sz = 16;
	
	int arr[16] = { 0 };

	for (int i = 0; i < sz; i++, c++)
	{

		Scalar x = img.at<uchar>(r, c);

		arr[i] = x.val[0];


	}

	for (int i = 0; i < sz; i++)
	{

		if (arr[i] == 0) {
			return false;
		}


	}

	return true;

}

bool isVertConnected(Mat img, int r, int c) {

	int sz = 16;
	
	int arr[16] = { 0 };

	for (int i = 0; i < sz; i++, c++)
	{

		Scalar x = img.at<uchar>(r, c);

		arr[i] = x.val[0];


	}

	
	for (int i = 0; i < sz; i++)
	{

		if (arr[i] == 255) {
			return true;
		}


	}

	return false;

}

int main()
{
	cv::Mat img = cv::imread("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Segmented Outputs\\mIMD002.bmp", 0);
	Mat grey;
	cv::imshow("First OpenCV Application", img);
	cv::waitKey(0);

	namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
	cv::moveWindow("First OpenCV Application", 0, 45);
	float si = 0, sj = 0, ei = 0, ej = 0;
	bool isStart = true;
	int isTrue = false;


	for (int i = 1; i < img.rows; i++)
	{
		for (int j = 1; j < img.cols; j++)
		{

			Scalar x = img.at<uchar>(i, j);

			if (1) {

				int v = 0;

				if (isHorConnected(img, i, j)) {
					v = 255;
				}
				else
				{
					v = 0;
				}



				img.row(i).col(j) = v;
			}





		}


	}

	cv::imshow("First OpenCV Application", img);
	cv::waitKey(0);

	for (int i = 1; i < img.rows; i++)
	{
		for (int j = 1; j < img.cols; j++)
		{

			Scalar x = img.at<uchar>(i, j);

			if (x.val[0] == 0) {

				int v = 0;

				if (isVertConnected(img, i, j)) {
					v = 255;
				}
				else
				{
					v = 0;
				}
				img.row(i).col(j) = v;



			}





		}


	}

	for (int i = 1; i < img.rows &&  false; i++)
	{
		for (int j = 1; j < img.cols; j++)
		{

			Scalar x = img.at<uchar>(i, j);

			if (x.val[0] == 255 && isStart) {

				si = i;
				sj = j;
				isStart = false;


			}

			ei = i;
			ej = j;

			cout << "\n Start: " << si << "  " << sj;
			cout << "\n End: " << ei << "  " << ej;

			for (int k = si; k < ei; k++)
			{

				for (int l = sj; l < ej; l++)
				{

					img.row(k).col(l) = 255;

				}



			}

		}

		
		isStart = true;

	}


	cv::imshow("First OpenCV Application", img);
	imwrite("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp", img);
	cout << "\nStart:  " << si << "    " << sj;
	cout << "\nEnd:    " << ei << "    " << ej;
	cout << "\nRows: " << img.rows;
	cout << "\nCols: " << img.cols;
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
