#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"

Scene g_Scene;

static EsceneType s_nextScene;

typedef struct tagTitleSceneData {
	Text TitleText[128];
} TitleSceneData;

void titleSceneInit(void) {
	g_Scene.Data = malloc(sizeof(TitleSceneData));
}

void titleSceneUpdate(void) {
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	TextCopyWithWhite(data->TitleText, L"�������");

	// �����̽� Ű�� ������ "�޷�"�� ��µǰ�.
	if (Input_GetKey(VK_SPACE)) {
		TextCopy(data->TitleText, L"�޷�", TEXT_COLOR_RED);
	}
}

void titleSceneRender(void) {
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawText(data->TitleText, TextLen(data->TitleText), 0, 0);
}

void titleSceneRelease(void) {
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

bool Scene_IsSetNextScene(void) {
	if (SCENE_NULL == s_nextScene) {
		return false;
	}
	else {
		return true;
	}
}

void Scene_SetNextScene(EsceneType scene) {
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_TITLE <= scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void) {
	assert(s_nextScene == SCENE_NULL);

	// ���� ���� ���� -> Release()
	//g_Scene.Release();

	// ������ �ε��� ���� ���缭 g_Scene�� ����
	//Scene_SetNextScene(g_Scene.Data);

	// ���� ���� �ʱ�ȭ -> Init()
	//s_nextScene = Init();

	// s_nextScene = 0;
	s_nextScene = SCENE_NULL;
}