#include <iostream>
#include "Struck2026.05.03.h"
using namespace std;

int main() {
	unsigned int size;
	cout << "Enter size: ";
	cin >> size;

	Product* product = new Product[size];

	for (size_t i = 0; i < size; i++) {
		product[i] = Auto_Create_product(10, 10, 10, 10, 10);
	}
	for (size_t i = 0; i < size; i++) {
		Print_product(product[i]);
	}
	//Sort_by_price(product, size);
	int price;
	cout << "price?\n";
	cin >> price;
	cout << "\n\n";
	//cout << "\nSorted arr:\n";
	bool t = Search_price(product, size, price);
	if (!t) {
		cout << "coundn`t find products with that price\n";
	}
	//for (size_t i = 0; i < size; i++) {
	//	Print_product(product[i]);
	//}
	//Byproduct(product, size);
	//while (true) {
	//	int id;
	//	Date date;
	//	string name;
	//	char* actname = nullptr;
	//	cout << "search for product for:\n1-id\n2-count\n3-name\n4-date\n5-exit search";
	//	unsigned short choise;
	//	cin >> choise;
	//	switch (choise)
	//	{
	//	case(1):
	//		cin >> id;
	//		Search_id(product, size, id);
	//		break;
	//	case(2):
	//		cin >> id;
	//		Search_count(product, size, id);
	//		break;
	//	case(3):
	//		cin >> name;
	//		actname = stringtoarrchar(name);
	//		Search_name(product, size, actname);
	//		break;
	//	case(4):
	//		cin >> date.day;
	//		cin >> date.month;
	//		cin >> date.year;
	//		Search_date(product, size, date);
	//		break;
	//	case(5):
	//		delete[] actname;
	//		goto breakwhile1;
	//		break;
	//	default:
	//		cout << "not an option";
	//		break;
	//	}

	//}

breakwhile1:
	//cout << "how many elements of top price:";
	//int countt;
	//cin >> countt;
	//PrintTopN(product, size, countt);
	delete[] product;
	return 0;
}