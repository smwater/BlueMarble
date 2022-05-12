#pragma once

#include <stdbool.h>
#include "Text.h"
#include "Common.h"

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);
void Renderer_Clear(void);

/// <summary>
/// 텍스트를 출력한다.
/// </summary>
/// <param name="text">텍스트</param>
/// <param name="numberOfChar">출력할 문자의 개수</param>
/// <param name="x">출력할 위치</param>
/// <param name="y">출력할 위치</param>
void Renderer_DrawText(const Text* text, int32 numberOfText, int32 x, int32 y);