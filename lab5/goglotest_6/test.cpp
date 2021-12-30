#include "pch.h"



TEST(Case1, Task6) {

  EXPECT_EQ(rec(1), 1);//min
  
}
TEST(Case2, Task6) {

	EXPECT_EQ(rec(2), 2);//min+1

}
TEST(Case3, Task6) {

	EXPECT_EQ(rec(80000), 2133333566);//max

}
TEST(Case4, Task6) {

	EXPECT_EQ(rec(79999), 2133332941);//max-1

}

