// mineswepper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <Windows.h>
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
void SetColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,
        (bgColor << 4) | textColor);
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
char settoe(char a) {
    if (a == '0') {
        //dpr('t');
        return 'E';
    }
    else {
        return a;
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
void saferun(T**& arr, int col, int row, int x,int y, funcarr& a) {
    int d=a.size();
    for (int i=0; d>i; i++) {
        if (not(((a.x(i) + x >= col) or (a.y(i) + y >= row)) or ((a.x(i) + x < 0) or (a.y(i) + y < 0)))){
            arr[x + a.x(i)][y + a.y(i)] = a.func(i)(arr[x + a.x(i)][y + a.y(i)]);
            
        }
    }
    return;
}
bool scanfor(char**& arr, int col, int row, char target, funcarr& func) {
    bool a = false;
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if (arr[i][j] == target) {
                a = true;
                saferun(arr, col, row, i, j, func);
            }
        }
    }
    return a;
}
template<typename T>
void opencel(T**& arr, T**& arr2, T**& arr3, int col, int row, int x, int y) {
    arr3[x][y] = 'O';
        if (arr[x][y] == arr2[x][y]) {
            funcarr a;
            a.addell(settoe, 1, 1);
            a.addell(settoe, -1, 1);
            a.addell(settoe, 1, -1);
            a.addell(settoe, -1, -1);
            a.addell(settoe, 1, 0);
            a.addell(settoe, 0, 1);
            a.addell(settoe, -1, 0);
            a.addell(settoe, 0, -1);
            
            saferun(arr3, col, row, x, y, a);
        }
        return;
}

char charminus(char a) {
    if (a < '9') {
        return --a;
    }
    else {
        return a;
    }
}
template<typename T>
void atcboardprint(T**& arr, T**& arr3, int col, int row) {
    std::cout << "  |";
    for (int i = 0; row > i; i++) {
        std::cout << i/10 << '|';
    }
    std::cout << '\n' << "  |";
    for (int i = 0; row > i; i++) {
        std::cout << i % 10 << '|';
    }
    std::cout << '\n' << "--+";
    for (int i = 0; row > i; i++) {
        std::cout << '-' << '-';
    }
    std::cout << '\n';
    for (int i = 0; col > i; i++) {
        std::cout << i / 10;
        std::cout << i % 10 << '|';
        for (int j = 0; row > j; j++) {
            if(arr3[i][j]=='O'){
                if (arr[i][j] == '0') {
                    std::cout << ' ' << ' ';
                }else{
                    std::cout << arr[i][j] << ' ';
                }
            }
            else {
                if (arr3[i][j] == 'F') {
                    SetColor(4, 8);
                    std::cout << 'F' ;
                    
                    SetColor(7, 0);
                    std::cout << ' ';
                }else{
                    SetColor(8, 8);
                    std::cout << 'M';
                    SetColor(7, 0);
                    std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "----------";
}
template<typename T>
void loseprint(T**& arr, int col, int row) {
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if (arr[i][j] == 'B') {
                SetColor(4, 0);
                std::cout << 'B';
                SetColor(7, 0);
            }
            else {
                SetColor(8, 8);
                std::cout << 'M';
                SetColor(7, 0);
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
int main()
{
    srand(time(NULL));
    SetColor(7, 0);
    int row=10;
    int col=10;
    int bombs = 10;
    cout << "how many rows?";
    std::cin >> row;
    cout << "how many cols?";
    std::cin >> col;
    cout << "how many bombs?";
    std::cin >> bombs;
    int obj = bombs;
    
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
    char** efflagfield = new char* [col];
    for (int i = 0; col > i; i++) {
        efflagfield[i] = new char[row];
    }
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            efflagfield[i][j] = '0';
        }
    }
    char** openedfield = new char* [col];
    for (int i = 0; col > i; i++) {
        openedfield[i] = new char[row];
    }
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            openedfield[i][j] = '0';
        }
    }
    atcboardprint(field, openedfield, col, row);
    for (int q=0; q < col * row; q++) {
        int x = col;
        int y = row;
        int boba = 0;
        bool f = 0;
        start:
        cout << "type of move: \n";
        cin >> boba;
        f = boba;
        cout << "x: \n";
        cin >> x;
        cout << "y: \n";
        cin >> y;
        if (x >= row or y >= col) {
            cout << "invalid move \n";
            goto start;
        }
        
        if (q == 0 and field[y][x] == 'B') {
            cout << "caught bomb on 1 move\n";
            goto start;
        }
        if (f) {
            if(openedfield[y][x] != 'O'){

            if (openedfield[y][x] != 'F') {
                funcarr b;
                b.addell(charadd, 1, 1);
                b.addell(charadd, -1, 1);
                b.addell(charadd, 1, -1);
                b.addell(charadd, -1, -1);
                b.addell(charadd, 1, 0);
                b.addell(charadd, 0, 1);
                b.addell(charadd, -1, 0);
                b.addell(charadd, 0, -1);
                saferun(efflagfield, col, row, y, x, b);
                openedfield[y][x] = 'F';
            }
            else {
                funcarr c;
                c.addell(charminus, 1, 1);
                c.addell(charminus, -1, 1);
                c.addell(charminus, 1, -1);
                c.addell(charminus, -1, -1);
                c.addell(charminus, 1, 0);
                c.addell(charminus, 0, 1);
                c.addell(charminus, -1, 0);
                c.addell(charminus, 0, -1);
                saferun(efflagfield, col, row, y, x, c);
                openedfield[y][x] = '0';
            }
            }
            else {
                cout << "invalid flag placement\n";
                goto start;
            }
        }
        else {
            if (openedfield[y][x] == 'F') {
                printf("flag on the opening ceil");
                goto start;
            }
            if (field[y][x] == 'B') {  
                lose:
                SetColor(7, 0);
                cout << "YOU LOST\n";
                loseprint(field, col, row);
                return 1;
            }
            else {
                //print(openedfield, col, row);
                openedfield[y][x] = 'E';
                bool g = true;
                while (g == true) {
                    g = false;
                    for (int i = 0; col > i; i++) {
                        for (int j = 0; row > j; j++) {
                            if (openedfield[i][j] == 'E') {
                                if (field[i][j] == 'B') {
                                    goto lose;
                                }
                                g = true;
                                opencel(field,efflagfield,openedfield, col, row, i, j);
                                
                            }
                        }
                    }
                }
            }
            
        
        }
        atcboardprint(field, openedfield, col, row);
        int b = 0;
        bool b2 = 0;
        for (int i = 0; col > i; i++) {
            for (int j = 0; row > j; j++) {
                if (field[i][j] == 'B') {
                    if (openedfield[i][j] != 'F') {
                        b2 = 1;
                    }
                    b++;
                }
            }
        }
        if (!b2 and b==bombs) {
            SetColor(7, 0);
            cout << "YOU WON\n";
            return 0;
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
