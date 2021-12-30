#include "pch.h"

TEST(Test_1, TestName) {
	//*************************** from c to s ********************//
	int arr_length = 5;
	char* arr = new char[arr_length];
	arr[0] = 'c';
	arr[1] = 'e';
	arr[2] = 'i';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_c_(arr, arr_length), "seil");
	//************************************************************//

	//*************************** from c to k ********************//
	arr[0] = 'c';
	arr[1] = 'l';
	arr[2] = 'i';
	arr[3] = 'n';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_c_(arr, arr_length), "klin");
	//************************************************************//

	//*************************** from C to S ********************//
	arr[0] = 'C';
	arr[1] = 'e';
	arr[2] = 'i';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_c_(arr, arr_length), "Seil");
	//************************************************************//

	//*************************** from C to K ********************//
	arr[0] = 'C';
	arr[1] = 'l';
	arr[2] = 'i';
	arr[3] = 'n';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_c_(arr, arr_length), "Klin");
	//************************************************************//
}
TEST(Test_2, TestName) {
	//*************************** from q to k ********************//
	int arr_length = 5;
	char* arr = new char[arr_length];
	arr[0] = 'q';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_q_(arr, arr_length), "kool");
	//************************************************************//

	//*************************** from q to k ********************//
	arr[0] = 'Q';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_q_(arr, arr_length), "Kool");
	//************************************************************//
}

TEST(Test_3, TestName) {
	//*************************** from qu to kv ********************//
	int arr_length = 5;
	char* arr = new char[arr_length];
	arr[0] = 'q';
	arr[1] = 'u';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "kvst");
	//************************************************************//

	//*************************** from QU to Kv ********************//
	arr[0] = 'Q';
	arr[1] = 'U';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "Kvst");
	//************************************************************//

	//*************************** from Qu to Kv ********************//
	arr[0] = 'Q';
	arr[1] = 'u';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "Kvst");
	//************************************************************//

	//*************************** from qU to kv ********************//
	arr[0] = 'q';
	arr[1] = 'U';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "kvst");
	//************************************************************//
}

TEST(Test_4, TestName) {
	//*************************** from x to ks ********************//
	int arr_length = 10;
	char* arr = new char[arr_length];
	arr[0] = 'x';
	arr[1] = 'o';
	arr[2] = 'r';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_x_(arr, arr_length), "ksort");
	//************************************************************//

	//*************************** from X to Ks ********************//
	arr[0] = 'X';
	arr[1] = 'o';
	arr[2] = 'r';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_x_(arr, arr_length), "Ksort");
	//************************************************************//

	//*************************** from X to Ks (x2) ********************//
	arr[0] = 'X';
	arr[1] = 'X';
	arr[2] = 'r';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_x_(arr, arr_length), "KsKsrt");
	//************************************************************//
}

TEST(Test_5, TestName) {
	//*************************** from w to v ********************//
	int arr_length = 5;
	char* arr = new char[arr_length];
	arr[0] = 'w';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_w_(arr, arr_length), "vool");
	//************************************************************//

	//*************************** from W to V ********************//
	arr[0] = 'W';
	arr[1] = 'o';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_w_(arr, arr_length), "Vool");
	//************************************************************//
}

TEST(Test_6, TestName) {
	//*************************** from ph to f ********************//
	int arr_length = 7;
	char* arr = new char[arr_length];
	arr[0] = 'p';
	arr[1] = 'h';
	arr[2] = 'e';
	arr[3] = 'n';
	arr[4] = 'i';
	arr[5] = 'x';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_ph_(arr, arr_length), "fenix");
	//************************************************************//

	//*************************** from PH to F ********************//
	arr[0] = 'P';
	arr[1] = 'H';
	arr[2] = 'e';
	arr[3] = 'n';
	arr[4] = 'i';
	arr[5] = 'x';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_ph_(arr, arr_length), "Fenix");
	//************************************************************//

	//*************************** from Ph to F ********************//
	arr[0] = 'P';
	arr[1] = 'h';
	arr[2] = 'e';
	arr[3] = 'n';
	arr[4] = 'i';
	arr[5] = 'x';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_ph_(arr, arr_length), "Fenix");
	//************************************************************//

	//*************************** from pH to f ********************//
	arr[0] = 'p';
	arr[1] = 'H';
	arr[2] = 'e';
	arr[3] = 'n';
	arr[4] = 'i';
	arr[5] = 'x';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_ph_(arr, arr_length), "fenix");
	//************************************************************//
}
TEST(Test_7, TestName) {
	//*************************** from you to u ********************//
	int arr_length = 7;
	int arr_copy = arr_length;

	char* arr = (char*)malloc(arr_length * sizeof(char));
	arr[0] = 'y';
	arr[1] = 'o';
	arr[2] = 'u';
	arr[3] = 'l';
	arr[4] = 'i';
	arr[5] = 'y';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_you_(arr, arr_copy), "uliy");
	//************************************************************//

	//*************************** from YOU to u ********************//
	arr_copy = arr_length;

	char* arr_1 = (char*)malloc(arr_length * sizeof(char));
	arr_1[0] = 'Y';
	arr_1[1] = 'O';
	arr_1[2] = 'U';
	arr_1[3] = 'l';
	arr_1[4] = 'i';
	arr_1[5] = 'y';
	arr_1[6] = '\0';
	ASSERT_STREQ(Replace_you_(arr_1, arr_copy), "Uliy");
	//************************************************************//

	//*************************** from You to u ********************//
	arr_copy = arr_length;

	char* arr_2 = (char*)malloc(arr_length * sizeof(char));
	arr_2[0] = 'Y';
	arr_2[1] = 'o';
	arr_2[2] = 'u';
	arr_2[3] = 'l';
	arr_2[4] = 'i';
	arr_2[5] = 'y';
	arr_2[6] = '\0';
	ASSERT_STREQ(Replace_you_(arr_2, arr_copy), "Uliy");
	//************************************************************//
}
TEST(Test_8, TestName) {
	//*************************** from oo to u ********************//
	int arr_length = 7;
	int arr_copy = arr_length;

	char* arr = (char*)malloc(arr_length * sizeof(char));
	arr[0] = 'o';
	arr[1] = 'o';
	arr[2] = 'u';
	arr[3] = 'l';
	arr[4] = 'i';
	arr[5] = 'y';
	arr[6] = '\0';
	ASSERT_STREQ(Replace_you_2(arr, arr_copy), "uuliy");
	//************************************************************//

	//*************************** from OO to u ********************//
	arr_copy = arr_length;

	char* arr_1 = (char*)malloc(arr_length * sizeof(char));
	arr_1[0] = 'O';
	arr_1[1] = 'O';
	arr_1[2] = 'u';
	arr_1[3] = 'l';
	arr_1[4] = 'i';
	arr_1[5] = 'y';
	arr_1[6] = '\0';
	ASSERT_STREQ(Replace_you_2(arr_1, arr_copy), "Uuliy");
	//************************************************************//

	//*************************** from Oo to u ********************//
	arr_copy = arr_length;

	char* arr_2 = (char*)malloc(arr_length * sizeof(char));
	arr_2[0] = 'O';
	arr_2[1] = 'o';
	arr_2[2] = 'u';
	arr_2[3] = 'l';
	arr_2[4] = 'i';
	arr_2[5] = 'y';
	arr_2[6] = '\0';
	ASSERT_STREQ(Replace_you_2(arr_2, arr_copy), "Uuliy");
	//************************************************************//

	//*************************** from oO to u ********************//
	arr_copy = arr_length;

	char* arr_3 = (char*)malloc(arr_length * sizeof(char));
	arr_3[0] = 'o';
	arr_3[1] = 'O';
	arr_3[2] = 'u';
	arr_3[3] = 'l';
	arr_3[4] = 'i';
	arr_3[5] = 'y';
	arr_3[6] = '\0';
	ASSERT_STREQ(Replace_you_2(arr_3, arr_copy), "uuliy");
	//************************************************************//
}
TEST(Test_9, TestName) {
	//*************************** from ee to i ********************//
	int arr_length = 5;
	int arr_copy = arr_length;
	char* arr = (char*)malloc(arr_length * sizeof(char));
	arr[0] = 'e';
	arr[1] = 'e';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_ee_(arr, arr_copy), "iol");
	//************************************************************//

	//*************************** from EE to i ********************//
	arr_copy = arr_length;
	char* arr_1 = (char*)malloc(arr_length * sizeof(char));
	arr_1[0] = 'E';
	arr_1[1] = 'E';
	arr_1[2] = 'o';
	arr_1[3] = 'l';
	arr_1[4] = '\0';
	ASSERT_STREQ(Replace_ee_(arr_1, arr_copy), "Iol");
	//************************************************************//

	//*************************** from Ee to i ********************//
	arr_copy = arr_length;
	char* arr_2 = (char*)malloc(arr_length * sizeof(char));
	arr_2[0] = 'E';
	arr_2[1] = 'e';
	arr_2[2] = 'o';
	arr_2[3] = 'l';
	arr_2[4] = '\0';
	ASSERT_STREQ(Replace_ee_(arr_2, arr_copy), "Iol");
	//************************************************************//

	//*************************** from ee to i ********************//
	arr_copy = arr_length;
	char* arr_3 = (char*)malloc(arr_length * sizeof(char));
	arr_3[0] = 'e';
	arr_3[1] = 'e';
	arr_3[2] = 'o';
	arr_3[3] = 'l';
	arr_3[4] = '\0';
	ASSERT_STREQ(Replace_ee_(arr_3, arr_copy), "iol");
	//************************************************************//
}

TEST(Test_10, TestName) {
	//*************************** from qu to kv ********************//
	int arr_length = 5;
	char* arr = new char[arr_length];
	arr[0] = 'q';
	arr[1] = 'u';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "kvst");
	//************************************************************//

	//*************************** from QU to Kv ********************//
	arr[0] = 'Q';
	arr[1] = 'U';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "Kvst");
	//************************************************************//

	//*************************** from Qu to Kv ********************//
	arr[0] = 'Q';
	arr[1] = 'u';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "Kvst");
	//************************************************************//

	//*************************** from qU to kv ********************//
	arr[0] = 'q';
	arr[1] = 'U';
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_qu_(arr, arr_length), "kvst");
	//************************************************************//
}
TEST(Test_11, TestName) {
	//*************************** from th to x ********************//
	int arr_length = 5;
	int arr_copy = arr_length;
	char* arr = (char*)malloc(arr_length * sizeof(char));
	arr[0] = 't';
	arr[1] = 'h';
	arr[2] = 'o';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(Replace_th_(arr, arr_copy), "zol");
	//************************************************************//

	//*************************** from TH to I ********************//
	arr_copy = arr_length;
	char* arr_1 = (char*)malloc(arr_length * sizeof(char));
	arr_1[0] = 'T';
	arr_1[1] = 'H';
	arr_1[2] = 'o';
	arr_1[3] = 'l';
	arr_1[4] = '\0';
	ASSERT_STREQ(Replace_th_(arr_1, arr_copy), "Zol");
	//************************************************************//

	//*************************** from Th to I ********************//
	arr_copy = arr_length;
	char* arr_2 = (char*)malloc(arr_length *
		sizeof(char));
	arr_2[0] = 'T';
	arr_2[1] = 'h';
	arr_2[2] = 'o';
	arr_2[3] = 'l';
	arr_2[4] = '\0';
	ASSERT_STREQ(Replace_th_(arr_2, arr_copy), "Zol");
	//************************************************************//

	//*************************** from tH to i ********************//
	arr_copy = arr_length;
	char* arr_3 = (char*)malloc(arr_length * sizeof(char));
	arr_3[0] = 't';
	arr_3[1] = 'H';
	arr_3[2] = 'o';
	arr_3[3] = 'l';
	arr_3[4] = '\0';
	ASSERT_STREQ(Replace_th_(arr_3, arr_copy), "zol");
	//************************************************************//
}
TEST(Test_12, TestName) {
	//*************************** remove_dublicate tttl ********************//
	int arr_length = 5;
	int arr_copy = arr_length;
	char* arr = (char*)malloc(arr_copy * sizeof(char));
	arr[0] = 't';
	arr[1] = 't';
	arr[2] = 't';
	arr[3] = 'l';
	arr[4] = '\0';
	ASSERT_STREQ(RemoveDublicate(arr, arr_copy), "tl");
	//************************************************************//

	//*************************** remove_dublicate TtTt ********************//
	arr_copy = arr_length;
	char* arr_1 = (char*)malloc(arr_copy * sizeof(char));

	arr_1[0] = 'T';
	arr_1[1] = 't';
	arr_1[2] = 'T';
	arr_1[3] = 't';
	arr_1[4] = '\0';
	ASSERT_STREQ(RemoveDublicate(arr_1, arr_copy), "T");
	//************************************************************//

	//*************************** remove_dublicate tttt ********************//
	arr_copy = arr_length;
	char* arr_2 = (char*)malloc(arr_copy * sizeof(char));

	arr_2[0] = 't';
	arr_2[1] = 't';
	arr_2[2] = 't';
	arr_2[3] = 't';
	arr_2[4] = '\0';
	ASSERT_STREQ(RemoveDublicate(arr_2, arr_copy), "t");
	//************************************************************//
}