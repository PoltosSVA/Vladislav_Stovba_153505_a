
#include "pch.h"

bool palin(std::string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1])
			return false;
	}
	return true;
}
bool prov(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[0])
			return false;
	}
	return true;
}