#include "rat.h"
#include <iostream>
#include "func.h"
#include "prov.h"

extern int N;
void client::set(int i){
	printf("\n������#_%d\n", i);

	printf("\n�������: ");
	string_chek(Last_name);

	printf("\n���: ");
	string_chek(First_name);

	printf("\n�����: ");
	string_chek(City);

	printf("\n�����: ");
	string_chek(Street);

	printf("\n���: ");
	house = get_address();

	printf("\n��������: ");
	flat = get_address();

	printf("\n������: ");
	Sale = get_address();
}
void client::get(int i) {
	printf("\n������#_%d\n", i);

	printf("\n�������: %s",Last_name);

	printf("\n���: %s", First_name);

	printf("\n�����: %s", City);

	printf("\n�����: %s",Street);

	printf("\n���: %d", house);

	printf("\n��������: %d", flat);

	printf("\n������: %d\n\n", Sale);

}