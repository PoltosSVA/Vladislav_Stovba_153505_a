#include "pch.h"

TEST(Case1, task1) {
  
  EXPECT_TRUE(lens("stroka\0"),6);
}
TEST(Case2, task1) {

	EXPECT_TRUE(lens("len"), 3);
}
TEST(Case3, task1) {

	EXPECT_TRUE(lens("Argentinamanitnegra"), 19);
}
TEST(Case4, task1) {

	EXPECT_TRUE(lens("."), 1);
}