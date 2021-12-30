#include "pch.h"

TEST(Case1, Task1) {

	char str[] = "0101 101001 0101001 01 101 11 10101 10101 10101 10011 01 01 10101001 11110 1101\0";

  EXPECT_EQ(func(str,90), 5);
  
}
TEST(Case2, Task1) {

	char str[] = "0\0";

	EXPECT_EQ(func(str, 90), 0);

}
TEST(Case3, Task1) {

	char str[] ="10101 10101 10101 \0";

	EXPECT_EQ(func(str, 90), 3);

}
TEST(Case4, Task1) {

	char str[] = "10101 0101 01 10 11 \0";

	EXPECT_EQ(func(str, 90), 1);

}