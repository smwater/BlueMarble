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
	sprintf_s(str, sizeof(str), "���� �Է� ����");

	if (Input_GetKeyDown(VK_UP)) {
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}

	if (Input_GetKeyDown(VK_DOWN)) {
		sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT)) {
		sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���� ����");
	}
}

void render(void) {
	Renderer_DrawText(str, sizeof(str));

	Renderer_Flip();

	Renderer_Cleanup();
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