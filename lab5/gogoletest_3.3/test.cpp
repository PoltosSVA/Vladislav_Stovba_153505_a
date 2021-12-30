#include "pch.h"



TEST(Case1, Task3_3) {
	
	int** f_A = new int* [4];
	
	int n = 2147483647;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,n,3,n };
	f_A[2] = new int[4]{ 3,n,3,n };
	f_A[3] = new int[4]{ 4,n,3,n };
	
	
	EXPECT_EQ(fre(f_A, 4, 4), 8);
 
  
}

TEST(Case2, Task3_3) {

	int** f_A = new int* [4];

	int n = -2147483648;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,n,3,n };
	f_A[2] = new int[4]{ 3,n,3,3 };//min
	f_A[3] = new int[4]{ 4,n,3,n };


	EXPECT_EQ(fre(f_A, 4, 4), 1);


}
TEST(Case3, Task3_3) {

	int** f_A = new int* [4];

	int n = -2147483647;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,n,3,n };
	f_A[2] = new int[4]{ 3,n,3,3 };//min+1
	f_A[3] = new int[4]{ 4,n,3,n };


	EXPECT_EQ(fre(f_A, 4, 4), 8);


}
TEST(Case4, Task3_3) {

	int** f_A = new int* [4];

	int n = 2147483646;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,n,3,1 };
	f_A[2] = new int[4]{ 3,1,3,n };
	f_A[3] = new int[4]{ 4,n,3,n };


	EXPECT_EQ(fre(f_A, 4, 4), 2);


}

