#include "pch.h"



TEST(Case1, task3_2) {
	
	int** f_A1 = new int* [5];
	int n = -2147483648;

	f_A1[0] = new int[4]{ 0,n,n,n };
	f_A1[1] = new int[4]{ 0,n,n,n };
	f_A1[2] = new int[4]{ 0,n,n,3 };//min
	
	
  EXPECT_EQ(Foo(f_A1,0,3, 4), 3);
  
}
TEST(Case2, task3_2) {

	int** f_A1 = new int* [5];
	int n = 2147483647;

	f_A1[0] = new int[4]{ 0,n,n,n };
	f_A1[1] = new int[4]{ 0,n,n,n };
	f_A1[2] = new int[4]{ 0,n,n,3 };//max


	EXPECT_EQ(Foo(f_A1, 0, 3, 4), 3);

}
TEST(Case3, task3_2) {

	int** f_A1 = new int* [5];
	int n = 2147483646;

	f_A1[0] = new int[4]{ 1,n,n,n };
	f_A1[1] = new int[4]{ 2,n,n,n };
	f_A1[2] = new int[4]{ 0,n,n,3 };//max-1


	EXPECT_EQ(Foo(f_A1, 0, 3, 4), 1);

}
TEST(Case4, task3_2) {

	int** f_A1 = new int* [5];
	int n = -2147483647;

	f_A1[0] = new int[4]{ 1,n,n,n };
	f_A1[1] = new int[4]{ 2,n,n,n };
	f_A1[2] = new int[4]{ 0,n,n,3 };//min+1


	EXPECT_EQ(Foo(f_A1, 0, 3, 4), 1);

}
