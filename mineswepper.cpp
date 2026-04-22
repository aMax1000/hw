// mineswepper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
using namespace std;
template<typename T>
void dpr(T e,char t=';') {
    cout << e << t;
}
template <typename T>
void resize(T*& arr, int oldsize, int size) {
    T* arr3 = new T[size];
    for (int i = 0; i < oldsize; i++) {
        arr3[i] = arr[i];
    }
    delete[] arr;
    arr = arr3;

}


typedef char (*ctocf)(char);
struct funcarr {
    pair<ctocf, pair<int, int>>* arr = new pair<ctocf, pair<int, int>>[1];
    int size1 = 0;
    ~funcarr() {
        delete[] arr;
    }
    void addell(char (*func)(char),int x,int y) {
        resize(arr, size1, size1 + 1);
        pair<ctocf, pair<int, int>> a;
        a.first = func;
        a.second.first = x;
        a.second.second = y;
        arr[size1] = a;
        size1++;
    }
    int size() {
        return size1;
    };
    int x(int i) {
        if (i < size1) {
            return (arr[i].second.first);
        }
        else {
            cout << "ERROR OUT OF INDEX X";
        }

    };
    int y(int i) {
        if (i < size1) {
            return (arr[i].second.second);
        }
        else {
            cout << "ERROR OUT OF INDEX Y";
        }
    };
    ctocf func(int i) {
        if (i < size1) {
            return (arr[i].first);
        }
        else {
            cout << "ERROR OUT OF INDEX FUNC";
        }
    };
};

char charadd(char a) {
    if (a == 'B') {
        return a;
    }
    else {
        return ++a;
    }
    
}


template<typename T>
void print(T** arr,int col,int row) {
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
template<typename T>
void boardprint(T** arr, int col, int row) {
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            switch (arr[i][j])
            {
            case('F'):
            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}
template<typename T>
void saferun(T**& arr, int col, int row, int x,int y, funcarr& a) {
    int d=a.size();
    for (int i=0; d>i; i++) {
        if (not((a.x(i) + x >= row or a.y(i) + y >= col) or (a.x(i) + x < 0 or a.y(i) + y < 0))){
            arr[x + a.x(i)][y + a.y(i)] = a.func(i)(arr[x + a.x(i)][y + a.y(i)]);
        }
    }
    return;
}
void scanfor(char**& arr, int col, int row, char target, funcarr& func) {
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if (arr[i][j] == target) {
                saferun(arr, col, row, i, j, func);
            }
        }
    }
    return;
}
template<typename T>
void opencel(T**& arr, T**& arr2, int col, int row, int x, int y) {
    if(not(arr2[y][x] ='1')){
        int a= (arr[y][x]-arr2[y][x]);
        if (a == 0) {
            if (not(1 + x >= row or 1 + y >= col)) {
                opencel(arr, arr2, col, row, x+1, y+1)
            }
            if (not(1 + x >= row or y-1 < 0)) {
                opencel(arr, arr2, col, row, x + 1, y - 1)
            }
            if (not(x-1 < 0 or 1 + y >= col)) {
                opencel(arr, arr2, col, row, x - 1, y + 1)
            }
            if (not(x-1 < 0 or y-1 < 0))) {
                opencel(arr, arr2, col, row, x - 1, y - 1)
            }
            
        }
    }
    return
}

int main()
{
    int row=10;
    int col=10;
    int obj = 20;
    char** field = new char* [col];
    for (int i = 0; col > i; i++) {
        field[i] = new char[row];
    }
    int totalcels = col * row;
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if ((rand() % totalcels) < obj) {
                field[i][j] = 'B';
                obj--;
            }
            else {
                field[i][j] = '0';
            }
            
            totalcels--;
        }
    }
    funcarr a;
    a.addell(charadd, 1, 1);
    a.addell(charadd, -1, 1);
    a.addell(charadd, 1, -1);
    a.addell(charadd, -1, -1);
    a.addell(charadd, 1, 0);
    a.addell(charadd, 0, 1);
    a.addell(charadd, -1, 0);
    a.addell(charadd, 0, -1);
    scanfor(field, col, row, 'B',a);
    print(field, col, row);
    char** openedfield = new char* [col];
    for (int i = 0; col > i; i++) {
        openedfield[i] = new char[row];
    }
    for (int q=0; q < col * row; q++) {
        int x = col;
        int y = row;
        start:
        cout << "make move \n";
        cin >> x;
        cin >> y;
        if (x >= col or y >= row) {
            cout << "invalid move \n";
            goto start;
        }
        if (q == 0 and field[x][y] == 'B') {
            goto start;
        }

    }
    
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
