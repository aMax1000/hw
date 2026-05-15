#include <iostream>
#include <bit>
#include <bitset>
using namespace std;
struct Fraction
{
	//все одно bitset не зміншуе розмір файлу
	bool sign;
	signed int x;
	signed int y;

	void generate() {
		x = rand() % 100;
		y = rand() % 100+1;
		sign = rand() % 2;
	}
};
int main()
{
	const unsigned int N = 100;
	Fraction infractions[N];
	Fraction fractions[N];
	FILE* file;
	for (int i = 0; i < N; i++) {
		infractions[i].generate();
	}
	for (int i = 0; i < N; i++)
	{

	}
	cout << endl << endl;
	if (fopen_s(&file, "fractions.bin", "wb") == 0)
	{
		for (int i = 0; i < N; i++)
		{
				fwrite(reinterpret_cast<const void*>(&infractions[i]), sizeof(Fraction), 1, file);
		}
		fclose(file);
	}
	if (fopen_s(&file, "fractions.bin", "rb") == 0)
	{
		fread(reinterpret_cast<void*>(fractions), sizeof(Fraction), N, file);
		for (int i = 0; i < N; i++)
		{
			cout << "input value:\n";
			if (!infractions[i].sign) {
				cout << '-';
			}
			cout << infractions[i].x << "/" << infractions[i].y << endl;
			cout << "output value:\n";
			if (!fractions[i].sign) {
				cout << '-';
			}
			cout <<fractions[i].x << "/" << fractions[i].y << endl <<endl;
		}
		fclose(file);
	}
	//Point p{ 4,5 };
	//int t = 100;
	//void* ptr = &t;
	//ptr = &p;
	//cout << (*(static_cast<Point*>(ptr))).y;

	//int n = 10;
	//char ch = 'A';
	//FILE* file;
	//if (fopen_s(&file, "data.bin", "wb") == 0)
	//{
	//	fwrite(reinterpret_cast<void*>(&n), sizeof(n), 1, file);
	//	fwrite(reinterpret_cast<void*>(&ch), sizeof(ch), 1, file);
	//	fclose(file);
	//}
	////bool double short
	//int nt;
	//char cht;
	//if (fopen_s(&file, "data.bin", "rb") == 0)
	//{
	//	fread(reinterpret_cast<void*>(&nt), sizeof(nt), 1, file);
	//	fread(reinterpret_cast<void*>(&cht), sizeof(cht), 1, file);
	//	cout << nt << " " << cht << endl;
	//	fclose(file);
	//}

	return 0;
}
