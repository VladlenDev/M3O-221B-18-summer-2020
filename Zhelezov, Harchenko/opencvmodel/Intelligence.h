#pragma once

#include "windowParam.h"

class Intelligence {
private:
	int targetPosX = WINDOW_WIDTH / 2, targetPosY = WINDOW_HEIGHT / 2;		//	current target position
	int targetShiftX, targetShiftY;		//	target last shift
	int targetNextX, targetNextY;		//	projecting target next position
	int nextX;							//	owner destination
public:
	void whereToGo(int tardx, int tardy);		//	projects target movement and sets owner destination
	void watchNewTarget();						//	watch after target

	int getNextX()
	{ return nextX; }
};