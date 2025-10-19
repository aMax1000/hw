
#include <iostream>
using namespace std;
int main()
{
    //1) Знайти добуток цілих непарних чисел, кратних 7 і від - 80 до 80.

    int a=-80;
    int b=80;
    int sum = 0;
    for (int c = a; c < b; c++) {
        if (c % 7 == 0) {
             sum *= c;
        }
    }
    cout << sum << endl;

    //2) Напишіть програму виведення всіх непарних чисел від 100 до 200 включно.

    a = 100;
    b = 200;
    for (int c = a; c < b; c++) {
        if (c % 2 == 1) {
            cout << c << endl;
        }
    }
    
}
