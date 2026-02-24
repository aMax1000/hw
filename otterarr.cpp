// otterarr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template <typename Tm1>
void outarr(Tm1* arr, Tm1 size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ',';
    }
    std::cout << '\n';
}
template <typename T>
class arr2 {
public:
    T* arr = new T[0];
    int size = 0;
    arr2(){};
    arr2(T*& arr2, int size2) {
        addar(arr2, size2);
    }
    void addar(T*& arr2, int size2) {
        T* arr3 = new T[size + size2];
        for (int i = 0; i < size; i++) {
            arr3[i] = arr[i];
        }
        for (int i = 0; i < size2; i++) {
            arr3[i+size] = arr2[i];
        }
        arr = arr3;
        size += size2;
    }

    void addar(arr2<int> arr2) {
        T* arr3 = new T[size + arr2.size];
        for (int i = 0; i < size; i++) {
            arr3[i] = arr[i];
        }
        for (int i = 0; i < arr2.size; i++) {
            arr3[i + size] = arr2.arr[i];
        }
        arr = arr3;
        size += arr2.size;
    }
    void push_back(T ell) {
        T* arr3 = new T[size + 1];
        for (int i = 0; i < size; i++) {
            arr3[i] = arr[i];
        }
        arr3[size] = ell;
        arr = arr3;
        size++;
    }
    void push_front(T ell) {
        T* arr3 = new T[size + 1];
        arr3[0] = ell;
        for (int i = 0; i < size; i++) {
            arr3[i+1] = arr[i];
        }
        arr = arr3;
        size++;
    }
    T back() {
        return arr[0];
    }
    T front() {
        return arr[size-1];
    }
    void pop_back() {
        T* arr3 = new T[size - 1];
        for (int i = 0; i < size - 1; i++) {
            arr3[i] = arr[i];
        }
        arr = arr3;
        size--;
    }
    void pop_front() {
        T* arr3 = new T[size - 1];
        for (int i = 0; i < size-1; i++) {
            arr3[i] = arr[i+1];
        }
        arr = arr3;
        size--;
    }
    void print(){
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ',';
        }
        std::cout << '\n';
    }
};



int main()
{
   int size = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    arr2<int> a(arr, size);
    a.addar(arr, size);
    
    a.addar(a);
    a.print();
    a.push_back(12);
    a.push_front(12);
    a.print();
    a.pop_back();
    a.pop_front();
    a.print();
    a.back();
    a.front();
    cout<< a.size << '\n';
    cout << a.arr;//pointer

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
