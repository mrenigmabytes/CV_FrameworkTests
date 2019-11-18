#include "cameraRead.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
using namespace cv;

const char* keys =
{
	"{help h usage ? | | pring this message }"
	"{@video | | Video file, if not defined try to use webcamera}"
};


cameraRead::cameraRead()
{
}

int main(int argc, const char** argv)
{
	CommandLineParser parser(argc, argv, keys);
	parser.about("Basic Video Test");

	if (parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}

	String videoFile = parser.get<String>(0);

	if (!parser.check())
	{
		parser.printErrors();
		return 0;
	}

	VideoCapture capture;
	if (videoFile != "")
	{
		capture.open(videoFile);
	}
	else
	{
		capture.open(0);
	}

	if (!capture.isOpened())
	{
		return -1;
	}

	namedWindow("video", 1);
	for (;;)
	{

		Mat frame, rgb[3],result;
		capture >> frame;

		split(frame, rgb);
		
		rgb[1] = Mat::zeros(frame.rows, frame.cols, CV_8U);
		
		Sobel(rgb[0], rgb[1], CV_8U, 1, 1);
		rgb[2] = rgb[2] - rgb[1];

		merge(rgb, 3, frame);

		Sobel(frame, frame, CV_8U, 1, 1);

		imshow("Video", frame);
		if (waitKey(30) >= 0) break;
	}

	capture.release();

	return 0;
}

cameraRead::~cameraRead()
{
}
