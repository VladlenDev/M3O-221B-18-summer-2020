#include "Intelligence.h"

void Intelligence::whereToGo(int tardx, int tardy)
{
	//	saving target last shift
	targetShiftX = tardx;
	targetShiftY = tardy;

	//	projecting target next position
	targetNextX = targetPosX + targetShiftX;
	targetNextY = targetPosY + targetShiftY;

	//	if target moves to bottom set destination to target projecting position, else - to middle
	if (targetShiftY > 0)
	{
		nextX = targetNextX;
	}
	else
	{
		nextX = WINDOW_WIDTH / 2;
	}

	//	saving target next position
	targetPosX = targetNextX;
	targetPosY = targetNextY;
}

void Intelligence::watchNewTarget()
{
	//	setting new target position
	targetPosX = WINDOW_WIDTH / 2;
	targetPosY = WINDOW_HEIGHT / 2;
}