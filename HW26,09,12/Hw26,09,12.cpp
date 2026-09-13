#include <iostream>
using namespace std;
#include "Phone.h"

int main()
{
	cout << "--PHONE--\n";
	Phone a1;
	a1.printInfo();
	a1.Init("Apple", "2042/42/42");
	a1.printInfo();

	cout << "\n\n\n--STUDENT--\n";
	Student a2;
	a2.printStudent();
	a2.Init("igor", "11", "the");
	a2.printStudent();

	a2.changeGroup("");
	a2.changeGroup("ehtt");
	a2.printStudent();



	cout << "\n\n\n--USER--\n";
	User a3;
	a3.showProfile();
	a3.Init("na", "em", "ps");
	a3.showProfile();

	a3.changePassword("ps", "newps");
	cout << "password is \"newps\"\n";
	a3.changePasswordManual();
	a3.showProfile();
}