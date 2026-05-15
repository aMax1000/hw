// otterhw2026.04.03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <chrono>
#include <iostream>
#include <stdlib.h>


template <typename T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i]<<' ';
    }
}

int* uneven(int* arr, int size, int& outsize) {
    int boba = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1 or !arr[i]) {
            boba++;
        }
    }
    outsize = boba;
    int* ret=new int[boba];
    int t = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1 or !arr[i]) {
            ret[t++] = arr[i];
        }
    }
    return ret;
}

int* newuneven(int* arr, int size, int& outsize) {
    int boba = 0;
    int* preret = (int*)malloc(size * sizeof(int)*0.6);
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1 or !arr[i]) {
            preret[boba++] = arr[i];
        }
    }
    outsize = boba;
    int* ret = (int*)realloc(preret, boba * sizeof(int));
    return ret;
}

using namespace std;
int main()
{
    // Get the current time from the system clock
   

    // Convert the current time to time since epoch
    

    // Convert duration to milliseconds


    // Print the result
    int size = 100000000;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    int size2;

    auto beg = chrono::high_resolution_clock::now();
    
    int* arr1 =uneven(array, size,size2);
    //print(arr1,size2);
    delete[] arr1;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - beg);
    
    std::cout << '\n' << duration.count() << '\n';

    beg = chrono::high_resolution_clock::now();

    int* arr2 = newuneven(array, size,size2);
    //print(arr2, size2);
    delete[] arr2;

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - beg);

    std::cout << '\n' << duration.count() << '\n';
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
