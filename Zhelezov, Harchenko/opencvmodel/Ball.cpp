#include "Ball.h"

Ball::Ball()
{
	int angleDeg = rand() % 360;		//	set angle in degrees

	//	stuped check for stuped angle
	if (angleDeg < 20 || (angleDeg > 180 && angleDeg < 200))
		angleDeg += 80;
	if (angleDeg > 340 || (angleDeg > 160 && angleDeg <= 180))
		angleDeg -= 80;
	if ((angleDeg >= 90 && angleDeg <= 94) ||(angleDeg >= 270 && angleDeg <= 274))
		angleDeg += 5;
	if ((angleDeg < 90 && angleDeg >= 86) || (angleDeg < 270 && angleDeg >= 266))
		angleDeg -= 5;

	angle = angleDeg * PI / 180;		//	transform to angle in radians

	//	set color
	b = rand() % 256;
	g = rand() % 256;
	r = rand() % 256;
}

void Ball::draw(cv::Mat frame)
{
	//	yeah, ball is a circle - MISS (Make It Simply Stuped pattern)
	cv::circle(frame, cv::Point(x, y), rad, cv::Scalar(b, g, r), cv::FILLED);
}

void Ball::move(clock_t deltaTime, Robot bot)
{
	//int dy, dx;		//	shift projections
	hit = false;	//	ball did not hit robot yet

	//	pre-calculating ball move
	shift = speed * deltaTime;
	dx = shift * cos(angle);
	dy = shift * sin(angle);

	//	bounces from vertical walls
	if (x + dx >= WINDOW_WIDTH || x + dx <= 0) {
		angle = PI - angle;
		dx = shift * cos(angle);
		dy = shift * sin(angle);
	}

	//	bounce from top wall
	if (y + dy <= 0) {
		angle = 2 * PI - angle;
		dx = shift * cos(angle);
		dy = shift * sin(angle);
	}

	//	bounce from robot
	if ((x + dx) >= (bot.getX() - bot.getWidth() * 3 / 4) && (x + dx) <= (bot.getX() + bot.getWidth() * 3 / 4) &&
		(y + dy) >= (bot.getY() - bot.getHeight() / 2) && (y + dy) <= (bot.getY() + bot.getHeight() / 2)) {
		angle = 2 * PI - angle;
		dx = shift * cos(angle);
		dy = shift * sin(angle);
		hit = true;
	}

	//	move
	x += dx;
	y += dy;
}

bool Ball::isAlive()
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
		return false;
	}
	return true;
}

void Ball::regenerate()
{
	Ball newBall;
	*this = newBall;
}