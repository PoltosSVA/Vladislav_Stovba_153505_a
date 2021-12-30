#include "pch.h"





TEST(Case1, Task3_1) {
	int** f_A = new int* [4];
	
	int n = -2147483648;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,1,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };//min

  EXPECT_EQ(res(f_A,3,4,1), -2147483648);
  
}
TEST(Case2, Task3_1) {
	int** f_A = new int* [4];

	int n = -2147483647;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,1,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };//min+1

	EXPECT_EQ(res(f_A, 3, 4, 1), 0);

}
TEST(Case3, Task3_1) {
	int** f_A = new int* [4];

	int n = 2147483647;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,1,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };//max

	EXPECT_EQ(res(f_A, 3, 4, 1), 0);

}
TEST(Case4, Task3_1) {
	int** f_A = new int* [4];

	int n = 2147483646;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,1,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };//max-1

	EXPECT_EQ(res(f_A, 3, 4, 1), 2147483646);

}TEST(Case5, Task3_1) {
	int** f_A = new int* [4];

	int n = 1073741823;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,2,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };

	EXPECT_EQ(res(f_A, 3, 4, 1), 2);

}
TEST(Case6, Task3_1) {
	int** f_A = new int* [4];

	int n = 1073741822;

	f_A[0] = new int[4]{ 1,n,3,n };
	f_A[1] = new int[4]{ 2,2,3,n };
	f_A[2] = new int[4]{ 3,n,n,3 };

	EXPECT_EQ(res(f_A, 3, 4, 1), 2147483644);

}