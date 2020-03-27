#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	double scale = 0.5;

	while (1) {
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
		Mat fframe;
		medianBlur(rFrame, fframe, 5);
		//imshow("whie: in the range", detectMat);
		imshow("frame", fframe);
		waitKey(30);
	}
}