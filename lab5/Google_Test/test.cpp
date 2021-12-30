#include "pch.h"


double vich(int n_A, int n_B) {
	double z = n_B / n_A;
	return -z;
}



TEST(Case1, Task1) {
  

  EXPECT_EQ(vich(1.7e+308, 1.7e+308), -1 );


}
TEST(Case2, Task1) {

	EXPECT_EQ(vich(1.7e+308 -1, 1.7e+308 -1), -1);
}
TEST(Case3, Task1) {

	EXPECT_EQ(vich(-1.7e-308, -1.7e-308 ), -1);
}
TEST(Case4, Task1) {

	EXPECT_EQ(vich(-1.7e-308 +1, -1.7e-308 +1), -1);
}
