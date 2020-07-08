#include "Finder.h"

Finder::Finder() : frameWidth(CAMERA_WIDTH), frameHeight(CAMERA_HEIGHT)
{
	backGroundColor = cv::Vec3b(BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED);
	targetColor = cv::Scalar(TARGET_BLUE, TARGET_GREEN, TARGET_RED);
}

Finder::Finder(int w, int h) : frameWidth(w), frameHeight(h)
{
	backGroundColor = cv::Vec3b(BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED);
	targetColor = cv::Scalar(TARGET_BLUE, TARGET_GREEN, TARGET_RED);
}

bool Finder::LocateCircle(cv::Mat frame)
{
	//	saving previous values
	int x = targetX, y = targetY;
	int prevRad = targetRad;

	//	target is not found yet
	targetFound = false;
	targetRad = 0;
	targetZ = frameHeight / 2;

	//	looking for circle
	for (int i = 0; i < frameWidth; i++)
	{
		if (frame.at<cv::Vec3b>(targetZ, i) != backGroundColor)
		{
			x = i;
			targetRad++;
		}
	}

	//	border crossing check
	if (x == frameWidth - 1 || x == targetRad - 1)
	{
		targetRad = prevRad * 2;
	}

	//	if circle is found
	if (targetRad > 0)
	{
		//	then circle is found
		targetFound = true;

		//	calculating circle parameters
		targetRad /= 2;
		x -= targetRad;
		y = (targetRad - 10) * UNDISTORTION_FACTOR;

		//	tracking
		targetDx = x - targetX;
		targetDy = y - targetY;

		//	updating target position info
		targetX = x;
		targetY = y;

		//	highlighting target
		cv::circle(frame, cv::Point(targetX, targetZ), targetRad, targetColor, 5);
	}

	return targetFound;
}