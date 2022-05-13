#pragma once

#include "Type.h"

typedef struct tagScene {
	void (*Init)(void);		// ���� �ʱ�ȭ �ϴ� �Լ�
	void (*Update)(void);	// ������Ʈ
	void (*Render)(void);	// ����
	void (*Release)(void);	// ������ ����� �ڿ��� ����
	void* Data;
} Scene;

typedef enum tagSceneType {
	SCENE_NULL,
	SCENE_TITLE = 1,
	SCENE_MAX
} EsceneType;

extern Scene g_Scene;

/// <summary>
/// ���� ������ ��ȯ�� �����ΰ�?
/// </summary>
/// <returns>���� ������ ��ȯ�� �����̸� true, �ƴϸ� false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// ���� ���� �����Ѵ�.
/// </summary>
/// <param name="scene">��</param>
void Scene_SetNextScene(EsceneType scene);

/// <summary>
/// �� ��ȯ
/// </summary>
void Scene_Change(void);