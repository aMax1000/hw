#include <iostream>
using namespace std;


int main()
{
	const char* path_to_file = "../data.txt";
	const char* mode = "w";
	FILE* file;
	errno_t code = fopen_s(&file, path_to_file, mode);
	unsigned int counter=0, lowercase1 =0, uppercase1 = 0;
	
	if (code == 0)//success
	{
		//fputs("Hello world", file);
		char ch;
		do
		{
			cout << "enter char: ";
			ch = getchar();
			if (ch == 's')
			{
				//break не працював
				break;
			}
			if (ch >= '0' && ch <= '9')
			{
				counter++;
			}
			if (ch >= 'A' && ch <= 'Z')
			{
				uppercase1++;
			}
			if (ch >= 'a' && ch <= 'z')
			{
				lowercase1++;
			}
			fputc(ch, file);
			cin.ignore();

		} while (true);
		fclose(file);
	}
	else
	{
		cout << code;
	}
	
	cout << "Digits: " << counter <<endl;
	cout << "lowercase: " << lowercase1 << endl;
	cout << "UPPERCASE: " << uppercase1 << endl;
	return 0;
}