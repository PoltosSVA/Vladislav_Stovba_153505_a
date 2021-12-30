#include "pch.h"

TEST(Case1, Task3) {
	char mas[] = "\0";


  EXPECT_EQ(lenstr(mas), 0);

}
TEST(Case2, Task3) {
	char mas[] = "awer\0";


	EXPECT_EQ(lenstr(mas), 4);

}
TEST(Case3, Task3) {
	char mas[] = "aaaaaaaaaaaaaaaaaaaaaaaaw\0";


	EXPECT_EQ(lenstr(mas),25);

}
