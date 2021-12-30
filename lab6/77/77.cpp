#include <iostream>
#include <string>

using namespace std;

bool palin(string str);
bool prov (string str);

int main() {

	setlocale(LC_ALL, "Rus");

	string str;
	getline(cin, str);

	if (prov(str)) {
		cout << "-1" << endl;
	}
	else {
		bool point = true;
		for (int i = str.length(); i >= 0; i--) {//перебор
			for (int j = 0; j <= str.length() - i; j++) {
				string wewe;
				wewe.insert(0, str, j, i);
				if (!palin(wewe)) {
					while (point) {
						cout << wewe.length();
						point = false;
					}
				}
			}
		}
	}
	return 0;
}

bool palin(string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1])
			return false;
	}
	return true;
}

bool prov(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[0])
			return false;
	}
	return true;
}