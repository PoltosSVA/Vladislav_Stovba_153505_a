#include "pch.h"

TEST(Case1, Task2) {
	int n = 2147483647;
	int* A = new int[7]{ n,n,n,n,n,n,n };//max
  EXPECT_EQ(Foo(0,A,3, 0),0);
}
TEST(Case2, Task2) {
	int n = -2147483648;
	int* A = new int[7]{ n,n,n,n,n,n,n };//min
	EXPECT_EQ(Foo(5, A,6, 0), 1);
}
TEST(Case3, Task2) {
	int n = 2147483647;
	int* A = new int[7]{ 3848537,-53687091,-143165576,2095106,2721779,n,n };
	EXPECT_EQ(Foo(0, A, 5, 0), 2);
}
TEST(Case4, Task2) {
	int n = 2147483647;
	int* A = new int[7]{ n,n,1814150311,477218,-2024026859,n,n };
	EXPECT_EQ(Foo(3, A, 7, 0), 1);
}
TEST(Case5, Task2) {
	int n = 2147483646;
	int* A = new int[7]{ n,n,n,n,n,n,n };//max-1
	EXPECT_EQ(Foo(0, A, 3, 0), 3);
}
TEST(Case6, Task2) {
	int n = -2147483647;
	int* A = new int[7]{ n,n,n,n,n,n,n };//min+1
	EXPECT_EQ(Foo(5, A, 6, 0), 1);
}