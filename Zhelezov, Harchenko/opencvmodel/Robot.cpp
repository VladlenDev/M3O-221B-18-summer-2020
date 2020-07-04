#include "Robot.h"

void Robot::draw(cv::Mat frame)
{
	//	yeah, robot is a line - MISS (Make It Simply Stuped pattern)
	cv::line(frame, cv::Point(x - width / 2, y), cv::Point(x + width / 2, y), cv::Scalar(192, 15, 255), height);
}

void Robot::move(clock_t deltaTime, int key)
{
	int dx = speed * deltaTime;				//	delta move

	if (x - dx + width <= WINDOW_WIDTH)		//	if it is possiple to move right
	{
		if (key == 'd' || key == 'D')		//	and user press 'D' key
			x += dx;						//	then move right
	}
	if (x + dx - width >= 0)				//	if it is possiple to move left
	{
		if (key == 'a' || key == 'A')		//	and user press 'A' key
			x -= dx;						//	then move left
	}
}

void Robot::autoMove(clock_t deltaTime, int tardx, int tardy)
{
	int nextX = x;					//	destination
	int dx = speed*deltaTime;		//	step, movement speed to destination

	//	ask mind for destination
	mind.whereToGo(tardx, tardy);
	nextX = mind.getNextX();

	//	if it is possible to move, move
	if ((nextX + width * 3 / 4) <= WINDOW_WIDTH && (nextX - width * 3 / 4) >= 0)
	{
		if (x < nextX)
		{
			x += dx;
		}
		if (x > nextX)
		{
			x -= dx;
		}
	}
}

void Robot::findNewBall()
{
	mind.watchNewTarget();
}