#pragma once

#include <stdbool.h>
#include "Text.h"
#include "Common.h"

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);
void Renderer_Clear(void);

/// <summary>
/// �ؽ�Ʈ�� ����Ѵ�.
/// </summary>
/// <param name="text">�ؽ�Ʈ</param>
/// <param name="numberOfChar">����� ������ ����</param>
/// <param name="x">����� ��ġ</param>
/// <param name="y">����� ��ġ</param>
void Renderer_DrawText(const Text* text, int32 numberOfText, int32 x, int32 y);