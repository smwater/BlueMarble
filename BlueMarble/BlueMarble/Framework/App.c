#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Timer.h"
#include "Renderer.h"
#include "Input.h"

bool App_Init(void) {
	if (false == Renderer_Init()) {
		return false;
	}

	if (false == Input_Init()) {
		return false;
	}

	return true;
}

void processInput(void) {
	Input_Update();
}

char str[128];
void update() {
	sprintf_s(str, sizeof(str), "현재 입력 없음");

	if (Input_GetKeyDown(VK_UP)) {
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}

	if (Input_GetKeyDown(VK_DOWN)) {
		sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT)) {
		sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시 눌림");
	}
}

void render(void) {
	Renderer_DrawText(str, sizeof(str));

	Renderer_Flip();

	Renderer_Cleanup();
}

int App_Run(void) {
	Timer_Init();

	// 게임 루프 : 입력처리 -> 게임 업데이트 -> 게임 출력
	while (true) {
		Timer_Update();

		processInput();
		update();
		render();
	}

	return 0;
}