#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include "windowParam.h"

//	message with counter to be showed in window
class Counter
{
private:
	int counter = 0, font = cv::FONT_HERSHEY_COMPLEX;
	double fontScale = 2;
	std::string countMes, countVal;
	cv::Point mesLoc, countLoc;
	cv::Scalar textColor;

public:
	Counter(const char* name, int xPos, int yPos);
	void draw(cv::Mat frame);
	void operator++(int);
	bool operator==(int val);
};