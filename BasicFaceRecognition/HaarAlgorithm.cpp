#include "HaarAlgorithm.h"
#include <iostream>
#include <string>
#include <sstream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


using namespace cv;
using namespace std;

HaarAlgorithm::HaarAlgorithm()
{
}

int main(int argc, char* argv[])
{
	string faceCascadeName = argv[1];
	CascadeClassifier faceCascade;

	if (!faceCascade.load(faceCascadeName))
	{
		cerr << "Error loading cascade file. Exiting!" << endl;
		return -1;
	}

	// Current frame
	Mat frame, frameGray;
	Mat frameROI;
	char ch;

	// Create the capture object
	// 0 -> input arg that specifies it should take the input from the webcam
	VideoCapture cap(0);

	

	// If you cannot open the webcam, stop the execution!
	if (!cap.isOpened())
		return -1;

	//create GUI windows
	namedWindow("Frame");

	// Scaling factor to resize the input frames from the webcam
	//float scalingFactor = 1.1;

	vector<Rect> faces;
	vector<Rect> *faces1 = &faces;

	// Iterate until the user presses the Esc key
	while (true)
	{
		// Capture the current frame
		cap >> frame;
		cap.set(CAP_PROP_FPS, 25);
		
		// Resize the frame
		//resize(frame, frame, Size(), scalingFactor, scalingFactor, INTER_AREA);

		// Convert to grayscale
		//cvtColor(frame, frameGray, CV_BGR2GRAY);

		// Equalize the histogram
		//equalizeHist(frameGray, frameGray);

		// Detect faces
		//faceCascade.detectMultiScale(frameGray, *faces1, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
		faceCascade.detectMultiScale(frame, *faces1, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));


		// Draw green rectangle around the face
		for (int i = 0; i < faces1->size(); i++)
		{
			//Rect faceRect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);

			// Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.
			int x = faces1->at(i).x - int(0.1*faces1->at(i).width);
			int y = faces1->at(i).y - int(0.0*faces1->at(i).height);
			int w = int(1.1 * faces1->at(i).width);
			int h = int(1.3 * faces1->at(i).height);

			// Extract region of interest (ROI) covering your face
			//frameROI = frame(Rect(x, y, w, h));

			//Rect bbox = cv::Rect(0, 0, frameROI.size().width, frameROI.size().height);
			Rect bounding = Rect(x, y, w, h);

			Scalar color = Scalar(255, 255, 0);
			rectangle(frame, bounding, color, 1, 8, 0);
			
			// Add the above masked images and place it in the original frame ROI to create the final image
			//add(maskedFace, maskedFrame, frame(Rect(x, y, w, h)));

		}

		// Show the current frame
		cv::imshow("Frame", frame);

		// Get the keyboard input and check if it's 'Esc'
		// 27 -> ASCII value of 'Esc' key
		ch = waitKey(1);
		if (ch == 27) {
			break;
		}
	}

	// Release the video capture object
	cap.release();

	// Close all windows
	cv::destroyAllWindows();

	return 1;
}





HaarAlgorithm::~HaarAlgorithm()
{
}
