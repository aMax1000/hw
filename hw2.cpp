// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    float a;
    float b;
    float c;
    char s = 'a';
    cin >> a;
    cin >> b;
    while (not(s=='+' or s == '-' or s == '*' or s == '/')){
        cout << "Input s\n";
        cin >> s;
    }
    
    switch (s)
    {
    case '+':
        cout << a + b; break;
    case '-':
        cout << a - b; break;
    case '*':
        cout << a * b; break;
    case '/':
        cout << a / b; break;
    default:
        break;
    }
    
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > b){
        if (a > c) {
            cout << a;
        }
        else {
            cout << c;
        }
    }
    else {
        if (b > c) {
            cout << b;
        }
        else {
            cout << c;
        }
    }

    cin >> a;
    cin >> b;
    cin >> c;
    cout << (a == b or b == c or c == a);
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
