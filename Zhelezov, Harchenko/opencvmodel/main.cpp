#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "windowParam.h"
#include "Box.h"
#include "Robot.h"
#include "Ball.h"
#include "Counter.h"
#include "ViewFrame.h"

#define CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace cv;

//	first one if for waitkey, second one is ESC key
const int DELAY = 10, ESC_KEY = 27;

void printUsage();

int main()
{
	printUsage();

	srand(time(NULL));			//	for new ball trajectory

	int key;					//	keyboard key
	float timeBuffer = 0;		//	for time magic
	clock_t deltaTime = 0;		//	also for time magic

	Robot robot;
	Ball ball;
	Box world;
	Counter hitsCounter("HITS", 10, 50);		//	message with hits counter
	Counter losesCounter("LOSES", 10 + WINDOW_WIDTH/2, 50);		//	message with loses counter
	ViewFrame mainWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "World model");		//	master window matrix

	//	main cycle
	while (true)
	{
		//	check for key pressing
		key = waitKey(DELAY);
		if (key == ESC_KEY)
			break;

		//	area
		mainWindow.update();
		robot.updateCam();

		//	objects action and drawing current world state
		world.draw(mainWindow.getFrame());

		ball.move(deltaTime, robot);
		ball.draw(mainWindow.getFrame(), robot.getCamFrame());

//		robot.move(deltaTime, key);		//	for control robot from keyboard
		robot.autoMove(deltaTime);
		robot.draw(mainWindow.getFrame());

		hitsCounter.draw(mainWindow.getFrame());
		losesCounter.draw(mainWindow.getFrame());

		//	check for collision
		if (ball.didHit()) {
			hitsCounter++;
			if (hitsCounter == 100)		//	easter egg
				ball = Ball(100);
		}

		//	check if ball ran away
		if (!ball.isAlive()) {
			ball.regenerate();
			robot.findNewBall();
			losesCounter++;
		}

		//	show current world state
		mainWindow.show();
		robot.showCam();

		//	time magic
		deltaTime = clock() - timeBuffer;
		timeBuffer = clock();
	}
	return 0;
}

void printUsage()
{
	cout << "::WORLD::MODEL::" << endl;
	cout << endl;
	cout << "Controls:" << endl;
//	cout << "[A] - move left" << endl;		//	for control robot from keyboard
//	cout << "[D] - move right" << endl;		//	for control robot from keyboard
	cout << "[Esc] - exit" << endl;
}