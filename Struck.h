

#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned int unit;
typedef unsigned short ushort;
const unit N = 50;
//структуры
struct Date {
	ushort day;
	ushort month;
	ushort year;
};

struct Product
{
	unit id;
	char* name;
	double price;
	unit count;
	Date date;
};


char* stringtoarrchar(string a) {
	char* arr = new char[a.size() + 1];
	for(int i=0;i<a.size();i++) {
		arr[i] = a[i];
	}
	arr[a.size()] = '\0';
	return arr;
}
template<typename T>
void spetialswap(pair<T,bool>& a, pair<T, bool>& b, bool (*comparefunc)(T, T)) {
	if (a.second == false) {
		return;
	}else {
		if (b.second == false) {
			swap(a, b);
			return;
		}
		else if (comparefunc(a.first, b.first)) {
			swap(a, b);
			return;
		}
		else {
			return;
		}
	}
}
template<typename T>
bool spetialswappredictor(pair<T, bool>& a, pair<T, bool>& b, bool (*comparefunc)(T, T)) {
	if (a.second == false) {
		return false;
	}
	else {
		if (b.second == false) {
			return true;
		}
		else if (comparefunc(a.first, b.first)) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool pricecomare(Product a, Product b) {
	return(a.price < b.price);
}

//функции
Product Create_product()
{
	Product pr;
	static int id = 1;
	pr.id = id++;
	cout << "Enter prise: ";
	cin >> pr.price;
	cout << "Enter count: ";
	cin >> pr.count;
	cout << "Enter date(YYY MM DD): ";
	cin >> pr.date.year >> pr.date.month >> pr.date.day;
	cout << "Enter name ";
	char name[N];
	cin.ignore();
	cin.getline(name, N);
	pr.name = new char[strlen(name) + 1];
	strcpy_s(pr.name, strlen(name) + 1, name);
	return pr;
}

int len(char* a) {
	int c = 0;
	while (true) {
		if (a[c]) {
			return c;
		}
		else {
			c++;
		}
	}
}

void Print_product(Product& pr)
{
	cout << "id" << pr.id << endl;
	cout << "name" << pr.name << endl;
	cout << "price" << pr.price << endl;
	cout << "count" << pr.count << endl;
	cout << "date(day month year)" << pr.date.day << "-" << pr.date.month << "-" << pr.date.year << endl;
}

void Sort_by_price(Product* prArr, unit size)
{
	if (prArr == nullptr) return;
	for (unit i = 0; i < size - 1; i++)
	{
		for (unit j = 0; j < size - i - 1; j++)
		{
			if (prArr[i].price > prArr[j + 1].price)
			{
				swap(prArr[i], prArr[j + 1]);
			}
		}
	}
}


void Search_id(Product* prID, unit size, unit id)
{
	if (prID == nullptr) return;
	for (unit i = 0; i < size; i++)
	{
		if (prID[i].id == id)
		{
			Print_product(prID[i]);
		}
	}
}
void Search_count(Product* prID, unit size, unit count)
{
	if (prID == nullptr) return;
	for (unit i = 0; i < size; i++)
	{
		if (prID[i].count == count)
		{
			Print_product(prID[i]);
		}
	}
}
void Search_name(Product* prID, unit size, char* arr)
{
	if (prID == nullptr) return;
	for (unit i = 0; i < size; i++)
	{
		for(int j=0;j<len(prID[i].name);j++){
			if (prID[i].name[j] != arr[j])
			{
				goto restart;
			}
		}
		Print_product(prID[i]);
		restart:;
	}
}
void Search_date(Product* prID, unit size, Date a)
{
	if (prID == nullptr) return;
	for (unit i = 0; i < size; i++)
	{
		if (prID[i].date.day==a.day and prID[i].date.month == a.month and prID[i].date.year == a.year) {
			Print_product(prID[i]);
		}
	}
}
void PrintTopN(Product* prID, unit size, int a) {
	pair<Product,bool>* arr = new pair<Product, bool>[a];
	for (int i = 0; i < a; i++) {
		arr[i].second = false;
	}
	for(int i=0;i<size;i++){
		for (int j = 0; j < a; j++) {
			if(j==0){
				pair<Product, bool> temp(prID[i], true);
				if (spetialswappredictor(temp, arr[0], pricecomare)) {

					spetialswap(temp, arr[0], pricecomare);
				}
				else {
					goto ifskipper;
				}

			}else{
				if(spetialswappredictor(arr[j - 1], arr[j], pricecomare)){
					spetialswap(arr[j - 1], arr[j], pricecomare);
				}
				else {
					goto ifskipper;
				}
			}
		ifskipper:;
		}
	}
	reverse(arr, arr + a);
	int ssize;
	if (a > size) {
		ssize = size;
		cout << "not enought products to fully full the list";
	}
	else {
		ssize = a;
	}
	for (int i = 0; i < ssize; i++) {
		Print_product(arr[i].first);
	}
}


Product* Product_data(unit size)
{
	Product* data = new Product[size];
	int id = 1;
	int min = 1;
	int max = 28;
	int let_min = 3;
	int let_max = 10;
	int wlmin = 'a', wlmax = 'z';
	for (size_t i = 0; i < size; i++)
	{
		data[i].id = id++;
		data[i].price = rand() % (max - min) + min;
		data[i].count = rand() % (max - min) + min;
		int letternumber = rand() % (let_max - let_min) + let_min;
		data[i].name = new char[letternumber + 1];
		size_t j;
		for (j = 0; j < letternumber; j++)
		{
			data[i].name[j] = rand() % (wlmax - wlmin) + wlmin;
		}
		data[i].name[j] = '\0';
		data[i].date.day = rand() % (max - min) + min;
		data[i].date.month = rand() % (12 - 1) + 1;
		data[i].date.year = 2027;
	}
	return data;
}
