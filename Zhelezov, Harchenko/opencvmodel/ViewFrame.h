#pragma once

#include <opencv2/opencv.hpp>

const int DEFAULT_WIDTH = 600, DEFAULT_HEIGHT = 800;

class ViewFrame 
{
	int width, height;		//	frame size
	std::string name;
	cv::Mat frame;

public:
	ViewFrame();		//	frame set up with default values
	ViewFrame(int w, int h, const char* str);		//	frame set up with current size and name
	void update();		//	frame clear

	void show() 
	{ cv::imshow(name, frame); }
	cv::Mat getFrame() 
	{ return frame; }
};