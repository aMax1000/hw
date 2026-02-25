#include <iostream>
using namespace std;
int allocationStepGlobal = 10;
template <typename Tm1>
void outarr(Tm1* arr, Tm1 size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ',';
    }
    std::cout << '\n';
}

template <typename T>
void resize(T*& arr, int oldsize,int size) {
    T* arr3 = new T[size];
    for (int i = 0; i < oldsize; i++) {
        arr3[i] = arr[i];
    }
    arr = arr3;
}




template <typename T>
void addelat(T*& arr, int size, T ell, int place) {
    T temp;
    T temp2 = ell;
    for (int i = place; i < size; i++) {
            temp = arr[i];
            arr[i] = temp2;
            temp2 = temp;
    }
}

template <typename T>
void advresize(T*& arr, int oldsize, int size, int shift = 0, int cut = 0) {
    T* arr3 = new T[size];
    for (int i = 0; i < oldsize; i++) {
        if (i >= cut) {
            arr3[i + shift] = arr[i];
        }
        else {
            arr3[i] = arr[i];
        }
    }
    arr = arr3;
}

template <typename T>
class arr2 {
public:
    T* arr = new T[0];
    int size = 0;
    int allsize = 0;
    int allocationStep = 10;
    T defaultell = 0;
    arr2() {};
    arr2(T*& arr2, int size2) {
        push_back(arr2, size2);
    }



    //array push

    void push_back(arr2<int> arr2) {
        push_back(arr2.arr, arr2.size);
    }
    void push_front(arr2<int> arr2) {
        push_front(arr2.arr, arr2.size);
    }
    void push_ell(arr2<int> arr2,int place) {
        push_ell(arr2.arr, arr2.size,place);
    }

    void push_back(T*& arr2, int size2) {
        if (size + size2 > allsize) {
            allsize = size + size2 + allocationStep - (size + size2) % allocationStep;
            resize(arr, size, allsize);
        }
        for (int i = 0; i < size2; i++) {
            arr[i + size] = arr2[i];
        }
        size += size2;
    }
    void push_front(T*& arr2, int size2) {
        if (size + size2 > allsize) {
            allsize = size + size2 + allocationStep - (size + size2) % allocationStep;
        }
        advresize(arr, size, allsize, size2);
        for (int i = 0; i < size2; i++) {
            arr[i] = arr2[i];
        }
        size += size2;
    }
    void push_ell(T*& arr2, int size2,int place) {
        if (size + size2 > allsize) {
            allsize = size + size2 + allocationStep - (size + size2) % allocationStep;
        }
        advresize(arr, size, allsize, size2, place);
        for (int i = 0; i < size2; i++) {
            arr[i+place] = arr2[i];
        }
        size += size2;
    }
    void pop_ell(int place,int len) {
        if (size -len <= allsize-allocationStep) {
            allsize = size - len +allocationStep - (size - len) % allocationStep;
        }
        advresize(arr, size, allsize, -len, place+len);
        size -= len;
    }
    void pop_back(int len) {
        if (size - len <= allsize - allocationStep) {
            allsize = size - len + allocationStep - (size - len) % allocationStep;
        }
        size -= len;
    }
    void pop_front(int len) {
        if (size - len <= allsize - allocationStep) {
            allsize = size - len + allocationStep - (size - len) % allocationStep;
        }
        advresize(arr, size, allsize, -len, len);
        size -= len;
    }








    //element push

    void push_back(T ell) {
        size++;
        if (size > allsize) {
            allsize += allocationStep;
            resize(arr, size, allsize);
        }
        arr[size-1] = ell;
    }


    void push_front(T ell) {
        size++;
        if (size > allsize) {
            allsize += allocationStep;
            advresize(arr, size, allsize, 1);
        }
        else {
            addelat(arr, size, ell, 0);
        }
    }


    void push_ell(T ell,int place) {
        size++;
        if (size > allsize) {
            allsize += allocationStep;
            resize(arr, size, allsize);
        }
        
        if (place > size-1) {
            if (place > allsize - 1) {
                allsize = place + allocationStep - place % allocationStep;
                resize(arr, size, allsize);
            }
            
            for (int i = size-1; i < place; i++) {
                arr[i] = defaultell;
            }
            size = place + 1;
            arr[place] = ell;
        }else{
            addelat(arr, size, ell, place);
        }
    }





    //element pop

    void pop_back() {
        size--;
        if (size <= allsize - allocationStep) {
            allsize -= allocationStep;
            resize(arr, size, allsize);
        }
    }


    void pop_front() {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size <= allsize - allocationStep) {
            allsize -= allocationStep;
            resize(arr, size, allsize);
        }
    }


    void pop_ell(int place) {
        for (int i = place; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size <= allsize - allocationStep) {
            allsize -= allocationStep;
            resize(arr, size, allsize);
        }

    }



    //otter

    T back() {
        return arr[0];
    }
    T front() {
        return arr[size - 1];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ',';
        }
        std::cout << '\n';
    }

    void srink() {
        resize(arr, size, size);
        allsize = size;
    }

    void newsize(int newsize) {
        resize(arr, size, newsize);
        allsize = newsize;
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
    arr2<int> b(arr, size);
    arr2<int> c(arr, size);
    for (int i = 0; i < c.size; i++) {
        c.arr[i] += 40;
    }
    a.print();
    a.push_back(arr, size);
    a.print();
    a.push_back(a);
    a.print();
    cout << a.size << '\n';
    cout << a.arr << '\n';//pointer
    a.push_front(12);
    a.print();
    a.push_back(12);
    a.print();
    a.srink();
    a.push_front(b);
    a.print();
    a.srink();
    a.push_back(b);
    a.print();
    a.srink();
    a.pop_back();
    a.print();
    a.srink();
    a.pop_front();
    a.print();
    a.push_ell(c,10);
    a.print();
    a.pop_ell(10, 5);
    a.print();
    a.pop_front(5);
    a.print();
    a.pop_back(5);
    a.print();
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
