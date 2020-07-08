#pragma once

#include <opencv2/opencv.hpp>
#include <ctime>
#include "windowParam.h"
#include "Intelligence.h"
#include "ViewFrame.h"
#include "Finder.h"

//	robot parameters
const int ROBO_WIDTH = 120, ROBO_HEIGHT = 40;
const float ROBOT_SPEED = 0.8;

class Robot
{
private:
	int x = WINDOW_WIDTH / 2, y = WINDOW_HEIGHT - WINDOW_HEIGHT / 20,
		width = ROBO_WIDTH, height = ROBO_HEIGHT;
	float speed = ROBOT_SPEED;
	Intelligence mind;							//	robot's intelligence, ball is a target
	ViewFrame cam;								//	static camera in center of robot's movement axis
	Finder ballFinder;							//	recognition module, ball is a target

public:
	Robot();
	void draw(cv::Mat frame);					//	drawing rules
	void move(clock_t deltaTime, int key);		//	manual control moving rules
	void autoMove(clock_t deltaTime);				//	moving rules
	void findNewBall();							//	says mind to watch after new target
	
	//	camera calls
	void updateCam()
	{ cam.update(); }
	void showCam()
	{ cam.show(); }
	cv::Mat getCamFrame()
	{ return cam.getFrame(); }

	int getX()
	{ return x; }
	int getY()
	{ return y; }
	int getWidth() 
	{ return width; }
	int getHeight()
	{ return height; }
};