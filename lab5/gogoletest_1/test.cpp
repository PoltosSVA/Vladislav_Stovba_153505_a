#include "pch.h"

TEST(Case1, Task1) {
  int n = 2147483647;	
  EXPECT_EQ(vich(n, n), -1);//max
 EXPECT_TRUE(true);
}
TEST(Case2, Task1) {
	EXPECT_EQ(vich(16777216 , 16777216*64), -64);
	EXPECT_TRUE(true);
}
TEST(Case3, Task1) {
	int n = -2147483648;
	EXPECT_EQ(vich(n, n), -1);//min
	EXPECT_TRUE(true);
}
TEST(Case4, Task1) {
	EXPECT_EQ(vich(-2097152, -2097152*1024), -1024);
	EXPECT_TRUE(true);
}
TEST(Case5, Task1) {
	int n = -2147483647;
	EXPECT_EQ(vich(573465, n), 3744);//min+1
	EXPECT_TRUE(true);
}
TEST(Case6, Task1) {
	int n = 2147483646;
	EXPECT_EQ(vich(213312, n), -10067);//max-1
	EXPECT_TRUE(true);
}
