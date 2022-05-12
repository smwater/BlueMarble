#include "Renderer.h"

HANDLE s_consoleHandle;
HANDLE s_screens[2];
int s_backBufferIndex;

bool Renderer_Init(void) {
	// 1. �ֿܼ� ���� �ڵ��� ��´�.
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == s_consoleHandle) {
		return false;
	}

	// 2. ��ũ���� �����.
	s_screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[0] == INVALID_HANDLE_VALUE) {
		return false;
	}

	s_screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[1] == INVALID_HANDLE_VALUE) {
		CloseHandle(s_screens[0]);

		return false;
	}

	return true;
}

void Renderer_Cleanup(void) {
	CloseHandle(s_consoleHandle);
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void Renderer_Flip(void) {
	// 1. ���� �ܼ��� ��ũ�� ���۸� �� ���۷� ����
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);

	// 2. �� ���� ��ȯ
	s_backBufferIndex = !s_backBufferIndex;
}

void Renderer_Clear(void) {
	HANDLE consoleHandle = s_screens[s_backBufferIndex];

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer_DrawText(const Text* text, int32 numberOfText, int32 x, int32 y) {
	// 1. �� ���ۿ� ���� �ڵ��� �����´�.
	HANDLE backBuffer = s_screens[s_backBufferIndex];

	// 2. Ŀ�� ��ġ�� �Ű��ش�.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. �� ���ۿ� �ؽ�Ʈ�� ����Ѵ�.
	for (int32 i = 0; i < numberOfText; i++) {
		SetConsoleTextAttribute(backBuffer, text->Attributes);
		WriteConsole(backBuffer, text, 1, NULL, NULL);
	}

	SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
}