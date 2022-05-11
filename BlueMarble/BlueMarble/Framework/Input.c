#include "Input.h"

bool s_prevKey[256];
bool s_nowKey[256];

// 입력부를 업데이트한다.
// 이전 프레임의 키 내용 저장 및 현재 프래임의 키 상태를 가져와야 함.
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

// 현재 프레임에 키가 눌렸다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKeyDown(uint8 vkey) {
	if (s_nowKey[vkey] == true && s_prevKey[vkey] == false) {
		return true;
	}

	return false;
}

// 현재 프레임에 키가 떼졌다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKeyUp(uint8 vkey) {
	if (s_nowKey[vkey] == false && s_prevKey[vkey] == true) {
		return true;
	}

	return false;
}

// 이전 프레임과 현재 프레임에 모두 키가 눌렸다면 true, 아니면 false
// vkey : 가상 키코드
bool Input_GetKey(uint8 vkey) {
	if (s_nowKey[vkey] == true && s_prevKey[vkey] == true) {
		return true;
	}

	return false;
}