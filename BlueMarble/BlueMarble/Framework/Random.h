#pragma once

#include "Type.h"

bool Random_Init();

/// <summary>
/// ������ ������ �����´�.
/// </summary>
/// <param name="minInclusive">�ּڰ�</param>
/// <param name="maxExclusive">�ִ�</param>
/// <returns>[minInclusive, maxExclusive) ������ ������ ����</returns>
int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive);

/// <summary>
/// ������ �Ǽ��� �����´�.
/// </summary>
/// <param name="minInclusive">�ּڰ�</param>
/// <param name="maxExclusive">�ִ�</param>
/// <returns>[minInclusive, maxExclusive) ������ ������ �Ǽ�</returns>
float Random_GetFNumberFromRange(float minInclusive, float maxExclusive);