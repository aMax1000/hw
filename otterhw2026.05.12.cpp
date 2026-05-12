#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	const char* path_to_file = "../data.txt";
	const char* mode = "r";
	FILE* file;
	errno_t code = fopen_s(&file, path_to_file, mode);
	unsigned int rows = 1, spaces = 0, letters = 0, words=0;

	if (code == 0)//success
	{
		bool word = false;
		char ch;
		while (!feof(file))
		{
			char ch=static_cast<char>(fgetc(file));
			if (ch == '\n') { 
				rows++;
			} 
			if (ch == ' ') { 
				spaces++; 
			} 
			if ((ch >= 'A' && ch <= 'Z') or (ch >= 'a' && ch <= 'z')) { 
				letters++; word = true; 
			} 
			if (word == true and (ch==' ' or ch=='\n')) {
				word = false; words++; 
			}
		}
		if (word) {
			words++;
		}
		fclose(file);
		cout << "Rows: " << rows << endl;
		cout << "Spaces: " << spaces << endl;
		cout << "Letters: " << letters << endl;
		cout << "Words: " << words << endl;
	}
	else {
		cout << "ERROR IN OPENING FILE";
	}
	return 0;
}