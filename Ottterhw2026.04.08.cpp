// Ottterhw2026.04.08.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
bool isvocal(char a) {
	switch (a)
	{
	case 'a':return true;
	case 'e':return true;
	case 'y':return true;
	case 'u':return true;
	case 'i':return true;
	case 'o':return true;
	case 'j':return true;
	case 'A':return true;
	case 'E':return true;
	case 'Y':return true;
	case 'U':return true;
	case 'I':return true;
	case 'O':return true;
	case 'J':return true;
	default: return false;
	}
}
bool strn(string a) {
	int x = 0;
	for (int i = 0; i < a.size(); i++) {
		x += (isvocal(a[i]));
	}
	return (a.size() > 10 and x * 2 < a.size());
}
int main()
{
	cout << strn("sd")<<endl;
	cout << strn("eaeUEsfsfs") << endl;
	cout << strn("eaeUEDsfsff") << endl;
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
