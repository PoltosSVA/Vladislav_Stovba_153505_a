#include <iostream>


using namespace std;



int main() {

	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	while(n > 0) {
		char s[120];
		char t[120];
		char s_p[120];

		cin >> s >> t;
		int point = 0; int j = 0;
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] != t[0]) {
				point++;
				continue;
			}
			
				s_p[0] = s[i];
				break;
			
		}
		for (int i = 1; t[i] != '\0'; i++) {
			point++;
			if (s[point] == '\0' || s[point] != t[i])
				break;
			j++;
			s_p[j] = s[point];
			
		}
		j++;
		point -= 2;
		for (point; point >= 0; point--) {
			if (t[j] == '\0')
				break;
			if (t[j] == s[point])
				s_p[j] = s[point];
			j++;
		}

		s_p[j] = '\0';
		if (!strcmp(s_p, t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		n--;


	}
	return 0;
}

