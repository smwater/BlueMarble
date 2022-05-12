#include "Timer.h"
#include <time.h>

clock_t s_prevTick;
float s_deltaTime;

bool Timer_Init(void) {
	s_prevTick = clock();

	return true;
}

void Timer_Update(void) {
	clock_t currentTick = clock();

	s_deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;

	s_prevTick = currentTick;
}

float Timer_GetDeltaTime(void) {
	return s_deltaTime;
}