#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
using namespace cv;

int main(int argc, const char** argv)
{
	Mat color;
	Mat gray;
	//read images
	try
	{
		color = imread("images/lena.jpg");
		if (color.data == NULL)
			throw std::exception("img file not found");
		gray = imread("images/lena.jpg", 0);
		if (gray.data == NULL)
			throw std::exception("img file not found");
	}
	catch (const std::exception& e)
	{
		cout << "Img File Not Found" << endl;
		return 1;
	}

	//write images
	imwrite("lenagray.jpg", gray);
	
	//pixel sample
	int pRow = color.cols - 1;
	int pCol = color.rows - 1;

	Vec3b pixel = color.at<Vec3b>(pRow, pCol);

	cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;

	//display images
	imshow("Lena BGR", color);
	imshow("Lena Gray", gray);

	waitKey(0);
	return 0;
}


