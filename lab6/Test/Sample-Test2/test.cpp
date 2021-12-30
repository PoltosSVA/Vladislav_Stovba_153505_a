#include "pch.h"

TEST(Case1, Task2) {
	char mas[] = "I am storm with armlet\0";
	

  EXPECT_EQ(func(mas,10), 50);
  
}
TEST(Case2, Task2) {
	char mas[] = "korsar\0";


	EXPECT_EQ(func(mas, 10), 10);

}