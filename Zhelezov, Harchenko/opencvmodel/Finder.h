#pragma once

#include <opencv2/opencv.hpp>
#include "windowParam.h"

//	background color
const int BACKGROUND_BLUE = 0;
const int BACKGROUND_GREEN = 0;
const int BACKGROUND_RED = 0;

//	target highlight color
const int TARGET_BLUE = 255;
const int TARGET_GREEN = 255;
const int TARGET_RED = 255;

class Finder
{
private:
	bool targetFound = false;
	int targetX = WINDOW_WIDTH / 2, targetY = WINDOW_HEIGHT / 2, targetZ = 0, targetRad = 0;
	int targetDx = 0, targetDy = 0;		//	target track
	int frameWidth, frameHeight;		//	frame size
	cv::Vec3b backGroundColor;			//	background color
	cv::Scalar targetColor;				//	target highlight color
public:
	Finder();							//	finder setup with default search frame size
	Finder(int w, int h);				//	finder setup with current search frame size
	bool LocateCircle(cv::Mat frame);	//	find a circle in the frame

	int getTargetDx()
	{ return targetDx; }
	int getTargetDy()
	{ return targetDy; }
};