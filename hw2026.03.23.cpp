// hw2026.03.23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void print(char* a) {
    int i = 0;
    while (a[i]) {
        std::cout << a[i];
        i++;
    }
    std::cout << '\n';
}

long long stringtoint(char* a) {
    int i = 0;
    long long value = 0;
    while (a[i]) {
        value *= 10;
        switch (a[i])
        {
        case '0':
        
            break;
        case '1':
            value += 1;
            break;
        case '2':
            value += 2;
            break;
        case '3':
            value += 3;
            break;
        case '4':
            value += 4;
            break;
        case '5':
            value += 5;
            break;
        case '6':
            value += 6;
            break;
        case '7':
            value += 7;
            break;
        case '8':
            value += 8;
            break;
        case '9':
            value += 9;
            break;
        default:
            break;
        }
        i++;
    }
    return value;
}
char* inttostring(long long a) {
    int len = floor(log10(a)) + 1;
    char* arr=new char[len+1];
    arr[len] = '\0';
    long long b = a;
    for (int i = 0; i < len;i++) {
        switch (b%10)
        {
        case 0:
            arr[len-i-1] = '0';
            break;
        case 1:
            arr[len - i - 1] = '1';
            break;
        case 2:
            arr[len - i - 1] = '2';
            break;
        case 3:
            arr[len - i - 1] = '3';
            break;
        case 4:
            arr[len - i - 1] = '4';
            break;
        case 5:
            arr[len - i - 1] = '5';
            break;
        case 6:
            arr[len - i - 1] = '6';
            break;
        case 7:
            arr[len - i - 1] = '7';
            break;
        case 8:
            arr[len - i - 1] = '8';
            break;
        case 9:
            arr[len - i - 1] = '9';
            break;
        default:
            break;
        }
        b /= 10;
    }

    return arr;
}


int main()
{
    int a = 21312;
    char* b = inttostring(a);
    int c = stringtoint(b);
    print(b);
    std::cout << c;
    delete[] b;
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
