#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int score;
    char mark;

    do {
        cout << "Enter score: ";
        cin >> score;
        if (score < 0 || score > 100) { 
            cout << "Помилка\n"; 
        }
    } while (score < 0 || score > 100);

    if (score >= 90) {
        mark = 'A';
    }
    else if (score >= 82) {
        mark = 'B';
    }
    else if (score >= 75) {
        mark = 'C';
    }
    else if (score >= 69) {
        mark = 'D';
    }
    else if (score >= 60) {
        mark = 'E';
    }
    else if (score >= 35) {
        mark = 'X';
    }
    else {
        mark = 'F';
    }

    cout << "ECTS grade: ";

    if (mark == 'X') {
        cout << "FX\n";
    }
    else {
        cout<< mark << '\n';
    }

    cout << "Результат: ";

        switch (mark) {
        case 'A':
            cout << "Відмінно\n";
            break;
        case 'B':
            cout << "Дуже добре\n";
            break;
        case 'C':
            cout << "Добре\n";
            break;
        case 'D':
            cout << "Задовільно\n";
            break;
        case 'E':
            cout << "Достатньо\n";
            break;
        case 'X':
            cout << "Незадовільно, але можливо повторне складання\n";
            break;
        case 'F':
            cout << "Незадовільно\n";
            break;
        }

    return 0;
}