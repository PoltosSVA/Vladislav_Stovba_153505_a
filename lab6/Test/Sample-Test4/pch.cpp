
#include "pch.h"
char* c_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 'c' || arr[i] == 'C') && arr[i + 1] != '\0' && (arr[i + 1] == 'e' || arr[i + 1] == 'i' || arr[i + 1] == 'y' ||
			arr[i + 1] == 'E' || arr[i + 1] == 'I' || arr[i + 1] == 'Y')) {
			if (arr[i] == 'c')
				arr[i] = 's';
			if (arr[i] == 'C')
				arr[i] = 'S';
		}
		else if (arr[i] == 'c' || arr[i] == 'C') {
			if (arr[i] == 'C')
				arr[i] = 'K';
			if (arr[i] == 'c')
				arr[i] = 'k';
		}

	}
	return arr;
}
char* q_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if (arr[i] == 'q' || arr[i] == 'Q') {
			if (arr[i] == 'q')
				arr[i] = 'k';
			if (arr[i] == 'Q')
				arr[i] = 'K';
		}
	}
	return arr;
}
char* qu_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 'q' || arr[i] == 'Q') && arr[i + 1] != '\0' && (arr[i + 1] == 'u' || arr[i + 1] == 'U')) {
			if (arr[i] == 'q')
				arr[i] = 'k';
			if (arr[i] == 'Q')
				arr[i] = 'K';

			arr[i + 1] = 'v';
		}
		else if (arr[i] == 'q' || arr[i] == 'Q') {
			if (arr[i] == 'q')
				arr[i] = 'k';
			if (arr[i] == 'Q')
				arr[i] = 'K';
		}
	}
	return arr;
}
char* x_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if (arr[i] == 'x' || arr[i] == 'X') {
			//arr = (char*)realloc(arr, (++arr_length) * sizeof(char));

			for (int k = arr_length - 1; k > i; k--) {
				arr[k] = arr[k - 1];
			}

			if (arr[i] == 'x')
				arr[i] = 'k';
			if (arr[i] == 'X')
				arr[i] = 'K';

			arr[i + 1] = 's';
		}
	}
	return arr;
}
char* w_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if (arr[i] == 'w' || arr[i] == 'W') {
			if (arr[i] == 'w')
				arr[i] = 'v';
			if (arr[i] == 'W')
				arr[i] = 'V';
		}
	}
	return arr;
}
char* ph_gl(char* arr, int arr_length) {
	for (int i = 0; i <
		arr_length; i++) {
		if ((arr[i] == 'p' || arr[i] == 'P') && arr[i + 1] != '\0' && (arr[i + 1] == 'h' || arr[i + 1] == 'H')) {
			for (int k = arr_length - 1, j = i; k > i; k--, j++) {
				arr[j + 1] = arr[j + 2];
			}
			//arr = (char*)realloc(arr, (--arr_length) * sizeof(char));
			if (arr[i] == 'p')
				arr[i] = 'f';
			if (arr[i] == 'P')
				arr[i] = 'F';
		}
	}
	return arr;
}
char* you_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 'y' || arr[i] == 'Y') && arr[i + 1] != '\0' && (arr[i + 1] == 'o' || arr[i + 1] == 'O') && arr[i + 2] != '\0' && (arr[i + 2] == 'u' || arr[i + 2] == 'U')) {

			for (int k = arr_length - 1, j = i; k > i; k--, j++) {
				if (arr[i] == 'Y')
					arr[i + 2] = 'U';
				if (arr[i] == 'y')
					arr[i + 2] = 'u';

				arr[j] = arr[j + 2];
			}
			arr_length -= 2;
			//arr = (char*)realloc(arr, (arr_length) * sizeof(char));
		}
	}
	return arr;
}
char* oo_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 'o' || arr[i] == 'O') && arr[i + 1] != '\0' && (arr[i + 1] == 'o' || arr[i + 1] == 'O')) {
			for (int k = arr_length - 1, j = i; k > i; k--, j++) {

				if (arr[i] == 'O')
					arr[i + 1] = 'U';
				if (arr[i] == 'o')
					arr[i + 1] = 'u';
				arr[j] = arr[j + 1];
			}
			//arr = (char*)realloc(arr, (--arr_length) * sizeof(char));

		}
	}
	return arr;
}
char* ee_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 'e' || arr[i] == 'E') && arr[i + 1] != '\0' && (arr[i + 1] == 'e' || arr[i + 1] == 'E')) {
			for (int k = arr_length - 1, j = i; k > i; k--, j++) {
				arr[j + 1] = arr[j + 2];
			}
			//arr = (char*)realloc(arr, (--arr_length) * sizeof(char));

			if (arr[i] == 'E')
				arr[i] = 'I';
			if (arr[i] == 'e')
				arr[i] = 'i';
		}
	}
	return arr;
}
char* th_gl(char* arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		if ((arr[i] == 't' || arr[i] == 'T') && arr[i + 1] != '\0' && (arr[i + 1] == 'h' || arr[i + 1] == 'H')) {
			for (int k = arr_length - 1, j = i; k > i; k--, j++) {
				arr[j + 1] = arr[j + 2];
			}
			//arr = (char*)realloc(arr, (--arr_length) * sizeof(char));
			if (arr[i] == 'T')
				arr[i] = 'Z';
			if (arr[i] == 't')
				arr[i] = 'z';
		}
	}
	return arr;
}

char* RemoveDublicate(char* arr, int arr_length) {
	for (int i = 0, j = i + 1; j < arr_length; i++, j++) {
		if (tolower(arr[i]) != 'a' || tolower(arr[i]) != 'e' || tolower(arr[i]) != 'i' ||
			tolower(arr[i]) != '0' || tolower(arr[i]) != 'u' || tolower(arr[i]) != 'y') {
			if (tolower(arr[j]) == tolower(arr[i])) {
				for (int k = j; k < arr_length - 1; k++) {
					arr[k] = arr[k + 1];
				}
				arr = (char*)realloc(arr, (--arr_length) * sizeof(char));
				if (tolower(arr[i]) == tolower(arr[j])) { //если после сдвига (поглощения дубликата) на месте
					i -= 1;
					j -= 1; //поглощенного дубликата окажется еще один
				}
			} //дубликат(два одинаковых рядом стояли)
		}
	}
	return arr;
}
