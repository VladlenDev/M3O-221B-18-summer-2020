#include "ViewFrame.h"

ViewFrame::ViewFrame()
{
	width = DEFAULT_WIDTH;
	height = DEFAULT_HEIGHT;
}

ViewFrame::ViewFrame(int w, int h, const char* str) : width(w), height(h)
{
	name = str;
	frame = cv::Mat::zeros(height, width, CV_8UC3);
}

void ViewFrame::update()
{
	//	clear frame matrix
	frame = cv::Mat::zeros(height, width, CV_8UC3);
}