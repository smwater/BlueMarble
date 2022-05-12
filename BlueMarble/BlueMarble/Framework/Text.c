#include "Text.h"

void TextCopy(Text* dest, const WCHAR* src, WORD attributes) {
	while (*src) {
		dest->Char.UnicodeChar = *src;
		dest->Attributes = attributes;

		++dest;
		++src;
	}
}

// wchar_t c = L'A'; 기존의 char 자료형은 유니코드 타입에 대응하지 못함
// 그래서 wchar_t를 사용. 크기는 2Bytes
// 유니코드 문자형을 출력하려면 swprintf_s로 해야함.

int32 TextLen(const Text* text) {
	int32 result = 0;
	while (text->Char.UnicodeChar) {
		++result;
		++text;
	}

	return result;
}
