#include "pch.h"



TEST(Case1, Task4) {
	
  EXPECT_EQ(F(1647, 1647,0, 3647), 9997);//max
  
}
TEST(Case2, Task4) {

	EXPECT_EQ(F(1646, 1646, 0, 3647), 10003);//max-1

}
TEST(Case3, Task4) {

	EXPECT_EQ(F(1, 1, 0, 10), 36);//min

}
TEST(Case4, Task4) {

	EXPECT_EQ(F(2, 2, 0, 10), 35);//min+1

}