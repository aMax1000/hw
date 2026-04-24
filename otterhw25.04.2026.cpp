// otterhw25.04.2026.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template<typename T>
void print(T** arr,int col,int row) {
    for (int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            cout<<arr[i][j]<<' ';
        }
        cout << '\n';
    }
    return;
}
template<typename T>
void checkrow(T** arr, int col, int row) {
    bool a = 1;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (arr[i][j] == true) {
                a = 0;
            }
        }
        if (a == 1) {
            cout << "row " << i+1 << " open\n";
        }
        a = 1;
    }
    return;
}

template<typename T>
void checkcol(T** arr, int col, int row) {
    bool a = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[j][i] == true) {
                a = 0;
            }
        }
        if (a == 1) {
            cout << "col " << i + 1 << " open\n";
        }
        a = 1;
    }
    return;
}
template<typename T>
void countrow(T** arr, int col, int row) {
    int a = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (arr[i][j] == true) {
                a++;
            }
        }
        cout << a << " seates at row" << i+1 << " occupied\n";
        a = 0;
    }
    return;
}

template<typename T>
void countcol(T** arr, int col, int row) {
    int a = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[j][i] == true) {
                a++;
            }
        }
        cout << a << " seates at col" << i + 1 << " occupied\n";
        a = 0;
    }
    return;
}



int main()
{
    srand(time(NULL));
    int col = 4;
    int row = 4;
    bool** arr = new bool* [col];
    for (int i = 0; i < col; i++) {
        arr[i] = new bool[row];
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            arr[i][j] = rand() % 2;
        }
        cout << '\n';
    }
    print(arr, col, row);
    cout << '\n';
    checkrow(arr, col, row);
    cout << '\n';
    checkcol(arr, col, row);
    cout << '\n';
    countrow(arr, col, row);
    cout << '\n';
    countcol(arr, col, row);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
