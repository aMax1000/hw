#include <iostream>
#include <cmath>
using namespace std;

template <typename Tm1>
void outarr(Tm1* arr, Tm1 size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '|';
    }
    std::cout << '\n';
}


template <typename Tm3>
void intactcheck(Tm3* arr1, Tm3* arr3, int size) {
    Tm3* arr2 = new Tm3[size];
    for (int i = 0; i < size; i++) {
        arr2[i] = arr3[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (arr1[i] == arr2[j]) {
                arr2[j] = arr2[size - i - 1];//remove swap
                break;
            }
            if (j == size - i - 1) {
                std::cout << "FAILED";
                delete[] arr2;
                return;
            }
        }
    }
    std::cout << "SUCCESS";
    delete[] arr2;
}
bool signbit(int a) {
    return a < 0;
}
template <typename T>
void arrrelok(T*& arr,int size){
    T* arr2 = new T[size];
    arr = arr2;
}

int main()
{
    srand(time(NULL));
    int size = 11;
    cin >> size;
    int* arr = new int[size] /*{ -6, -7, 4, 1, -1, -5, -2, 10, 3, 5, 6 }*/;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 10;
    }
    int* backuparr = new int[size];
    for (int i = 0; i < size; i++) {
        backuparr[i] = arr[i];
    }





    //для разделения на положительные и отрицательные числа за 1 проход массива, 
    //в начало переносятся положительные а в конец отрицательные
    //потом делается 2 указателя на положительную и отрицательную часть массива
    //этот алгоритм не тратит дополнительной памяти
    //так же создал функцию intactcheck которая проверяет все ли элементы изначального массива попали в конечный
    int temp;
    int* head1 = arr;
    int* head2 = arr + size - 1;
    int* arr2 = 0;
    int sizearr1 = 1;
    int sizearr2;
    for (int i = 0; i < size; i++) {
        if (signbit(*head1) == 0) {
            head1++;
            sizearr1++;
        }
        else if (signbit(*head2) == 1) {
            head2--;
        }
        if (signbit(*head1) == 1 && signbit(*head2) == 0) {
            temp = *head1;
            *head1 = *head2;
            *head2 = temp;
        }
        if (head1 + 1 == head2) {
            arr2 = head2;
            if (signbit(*head1) == 1) {
                sizearr1--;
                arr2--;
            }
            sizearr2 = size - sizearr1;
            break;
        }
    }
    
    int* arr3 = new int[sizearr1];
    arr3 = arr;

    outarr(backuparr, size);
    outarr(arr, size);
    outarr(arr3, sizearr1);
    outarr(arr2, sizearr2);
    intactcheck(arr, backuparr, size);
    delete[] arr2;
    delete[] arr3;
    delete[] backuparr;
}
