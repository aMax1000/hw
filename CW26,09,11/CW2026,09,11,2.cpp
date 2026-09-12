// cW2026,09,11,2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bancomat.h"
using namespace std;
int main()
{
    Bancomat a(1, {{1000,10}, {100,1}, {10,23}}, 21, 10000);
    a.Print();
    cout << endl << "Not Depo: " << a.Withdraw(10)<<endl;
    a.Print();
    cout << endl << "Not Depo: " << a.Deposit(200) << endl;
    a.Print();
    cout << endl << "Not With: " << a.Withdraw(199) << endl;
    a.Print();
    cout << endl <<"Not With: "<<a.Withdraw(9500) << endl;
    a.Print();
    Bancomat b(1, { {1000,10}, {10000,1}, {10,23} }, 21, 10000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
