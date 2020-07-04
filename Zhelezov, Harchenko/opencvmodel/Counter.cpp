#include "Counter.h"

Counter::Counter(const char* name, int xPos, int yPos)
{
	countMes = name;
	countMes += ": ";

	countVal = std::to_string(counter);

	mesLoc = cv::Point(xPos, yPos);
	countLoc = cv::Point(xPos + countMes.length() * fontScale * 16, yPos);

	textColor = cv::Scalar(250, 250, 250);
}

void Counter::draw(cv::Mat frame)
{
	putText(frame, countMes, mesLoc, font, fontScale, textColor);
	putText(frame, countVal, countLoc, font, fontScale, textColor);
}

void Counter::operator++(int)
{
	counter++;
	countVal = std::to_string(counter);
}