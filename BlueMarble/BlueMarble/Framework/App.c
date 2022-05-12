#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Timer.h"
#include "Renderer.h"
#include "Input.h"
#include "Random.h"

bool App_Init(void) {
	if (false == Renderer_Init()) {
		return false;
	}

	Random_Init();

	return true;
}

void processInput(void) {
	Input_Update();
}

char str[2][128];
void update() {
	int32 minVal = -45;
	int32 maxVal = 32;
	int32 randInt = Random_GetNumberFromRange(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d ������ ���� : %d\n", minVal, maxVal, randInt);

	float fminVal = -12.342f;
	float fmaxVal = 25.982;
	float frand = Random_GetFNumberFromRange(fminVal, fmaxVal);
	assert(fminVal <= frand && frand <= maxVal);

	sprintf_s(str[1], sizeof(str[1]), "%f ~ %f ������ �Ǽ� : %f", fminVal, fmaxVal, frand);
}

void render(void) {
	Renderer_DrawText(str[0], strlen(str[0]));
	Renderer_DrawText(str[1], strlen(str[1]));
	Renderer_Flip();

	Renderer_Clear();

	Sleep(100);
}

int App_Run(void) {
	Timer_Init();

	// ���� ���� : �Է�ó�� -> ���� ������Ʈ -> ���� ���
	while (true) {
		Timer_Update();

		processInput();
		update();
		render();
	}

	return 0;
}