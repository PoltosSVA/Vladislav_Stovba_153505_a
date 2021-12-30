#include "pch.h"



TEST(Case1, Task5) {

  EXPECT_EQ(rec(1,1,1), 0);//min
  
}

TEST(Case2, Task5) {

	EXPECT_EQ(rec(2, 2, 2), 1);//min+1

}
TEST(Case3, Task5) {

	EXPECT_EQ(rec(33, 33, 5), 435897);//max

}
TEST(Case, Task5) {

	EXPECT_EQ(rec(32, 32, 4), 52360);//max-1

}