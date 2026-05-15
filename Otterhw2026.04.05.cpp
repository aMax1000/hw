#include <iostream>
template <typename T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\n';
    }
}

template <typename T>
void print(T** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
template <typename T>
T* aboba(T** arr, int row, int col) {
    T* outarr = new T[row];
    for (int i = 0; i < row; i++) {
        outarr[i] = arr[i][0];
        for (int j = 1; j < col; j++) {
            outarr[i]+=arr[i][j];
        }
    }
    return outarr;
}
int main()
{
    int row = 10;
    int col = 10;
    int** arr2d = new int* [row];
    for (int i = 0; i < row; i++) {
        arr2d[i] = new int [col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr2d[i][j] = rand() % 10;
        }
    }
    print(arr2d, row, col);
    std::cout << '\n';
    int* a = aboba(arr2d, row, col);
    print(a, row);
    delete[] a;
    for (int i = 0; i < row; i++) {
        delete[] arr2d[i];
    }
    delete[] arr2d;
}
