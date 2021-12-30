#include "rat.h"
#include <iostream>
#include "func.h"
#include "prov.h"

extern int N;
void client::set(int i){
	printf("\nКлиент#_%d\n", i);

	printf("\nФамилия: ");
	string_chek(Last_name);

	printf("\nИмя: ");
	string_chek(First_name);

	printf("\nГород: ");
	string_chek(City);

	printf("\nУлица: ");
	string_chek(Street);

	printf("\nДом: ");
	house = get_address();

	printf("\nКвартира: ");
	flat = get_address();

	printf("\nСкидка: ");
	Sale = get_address();
}
void client::get(int i) {
	printf("\nКлиент#_%d\n", i);

	printf("\nФамилия: %s",Last_name);

	printf("\nИмя: %s", First_name);

	printf("\nГород: %s", City);

	printf("\nУлица: %s",Street);

	printf("\nДом: %d", house);

	printf("\nКвартира: %d", flat);

	printf("\nСкидка: %d\n\n", Sale);

}