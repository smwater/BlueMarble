#include "Input.h"

bool s_prevKey[256];
bool s_nowKey[256];

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;� ��.
void Input_Update(void) {
	memcpy(s_prevKey, s_nowKey, sizeof(s_nowKey));

	for (int vkey = 0; vkey < 256; vkey++) {
		if (GetAsyncKeyState(vkey) & 0x8000) {
			s_nowKey[vkey] = true;
		}
		else {
			s_nowKey[vkey] = false;
		}
	}
}

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyDown(uint8 vkey) {
	if (s_nowKey[vkey] == true && s_prevKey[vkey] == false) {
		return true;
	}

	return false;
}

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyUp(uint8 vkey) {
	if (s_nowKey[vkey] == false && s_prevKey[vkey] == true) {
		return true;
	}

	return false;
}

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKey(uint8 vkey) {
	if (s_nowKey[vkey] == true && s_prevKey[vkey] == true) {
		return true;
	}

	return false;
}