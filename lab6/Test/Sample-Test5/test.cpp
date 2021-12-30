#include "pch.h"

TEST(Case1, Task5) {
	char str_1[] = "aboba";
	char str_2[] = "obaba";
	int dl_1 = 5;
	int dl_2 = 5;
	int len = 7;
	int m = 10;
	int col=3;
  EXPECT_EQ(s_s1(str_1,str_2,len,dl_1,dl_2,m,col), 1);
}
TEST(Case2, Task5) {
	char str_1[] = "col";
	char str_2[] = "col";
	int dl_1 = 3;
	int dl_2 = 3;
	int len = 3;
	int m = 10;
	int col = 3;
	EXPECT_EQ(s_s1(str_1, str_2, len, dl_1, dl_2, m, col), 1);
}
TEST(Case3, Task5) {
	char str_1[] = "asdf";
	char str_2[] = "wewe";
	int dl_1 = 4;
	int dl_2 = 4;
	int len = 4;
	int m = 10;
	
	int col = 0;
	EXPECT_EQ(s_s1(str_1, str_2, len, dl_1, dl_2, m, col), 0);
}
TEST(Case4, Task5) {
	char str_1[] = "aswe";
	char str_2[] = "wewewe";
	int dl_1 = 4;
	int dl_2 = 6;
	int len = 7;
	int m = 10;

	int col = 0;
	EXPECT_EQ(s_s1(str_1, str_2, len, dl_1, dl_2, m, col), 0);
}