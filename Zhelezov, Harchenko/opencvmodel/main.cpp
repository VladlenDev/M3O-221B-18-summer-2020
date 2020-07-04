#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "windowParam.h"
#include "Box.h"
#include "Robot.h"
#include "Ball.h"
#include "Counter.h"

using namespace std;
using namespace cv;

//	first one if for waitkey, second one is ESC key
const int DELAY = 10, ESC_KEY = 27;

void printUsage();

int main()
{
	printUsage();

	srand(time(NULL));		//	for new ball trajectory

	int key;		//	keyboard key
	float timeBuffer = 0;		//	for time magic
	clock_t deltaTime = 0;		//	also for time magic

	Robot robot;
	Ball ball;
	Box world;
	Counter hitsCounter("HITS");		//	message with hits counter

	//	master window matrix
	Mat frame = Mat::zeros(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3);

	//	main cycle
	while (true)
	{
		//	check for key pressing
		key = waitKey(DELAY);
		if (key == ESC_KEY)
			break;

		//	area
		frame = Mat::zeros(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3);

		//	action
		robot.move(deltaTime, key);
		ball.move(deltaTime, robot);

		//	check for collision
		if (ball.didHit()) {
			hitsCounter++;
		}

		//	drawing current world state
		world.draw(frame);
		ball.draw(frame);
		if (!ball.isAlive()) {
			ball.regenerate();
		}
		robot.draw(frame);
		hitsCounter.draw(frame);

		//	show current world state
		imshow("World model", frame);

		//	time magic
		deltaTime = clock() - timeBuffer;
		timeBuffer = clock();
	}
	return 0;
}

void printUsage() {
	cout << "::WORLD::MODEL::" << endl;
	cout << endl;
	cout << "Controls:" << endl;
	cout << "[A] - move left" << endl;
	cout << "[D] - move right" << endl;
	cout << "[Esc] - exit" << endl;
}