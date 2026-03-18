#pragma once
#include <iostream>
int len1(char* string) {
	int size = 0;
	while (true) {
		if (string[size] == '\0') {
			return size;
		}
		size++;
	}
}


class otterstring {
public:
	char* string = nullptr;
	otterstring() {
		string = new char[1];
		string[0] = '\0';
	}
	otterstring(char* arr,int size) {
		string = new char[size + 1];
		for (int i = 0; i < size; i++) {
			string[i] = arr[i];
		}
		string[size] = '\0';
	}
	/*otterstring(cutotterstring a) {
		string = new char[a.len + 1];
		for(int i=0;i<a.len;i++){
			string[i] = (*a.pointer).string[i];
		}
		string[a.len] = '\0';
	}*/
	~otterstring() {
		delete[] string;
	}

	int len() {
		int size = 0;
		while (true) {
			if (string[size] == '\0') {
				return size;
			}
			size++;
		}
	}

	void my_concate(char* arr, int size) {
		int len = len1(string);
		char* string2 = new char[size + len+1];
		int i = 0;
		for(int i = 0; i < len;i++){
			string2[i] = string[i];
		}
		for (int i = 0; i < size; i++) {
			string2[i+len] = arr[i];
		}
		string2[size+len] = '\0';
		delete[] string;
		string = string2;
	}

	void my_concate(otterstring& string3) {
		int len = len1(string);
		int len2 = string3.len();
		char* string2 = new char[len + len2+1];
		int i = 0;
		for (int i = 0; i < len; i++) {
			string2[i] = string[i];
		}
		for (int i = 0; i < len2; i++) {
			string2[i + len] = string3.string[i];
		}
		string2[len2 + len] = '\0';
		delete[] string;
		string = string2;
	}
	void print() {
		int i = 0;
		while (true) {
			if (string[i] == '\0') {
				std::cout << '\n';
				return;
			}
			std::cout << string[i] << ',';
			i++;
		}
		
	}
	int findstring(otterstring& a) {
		int i = 0;
		int counter = 0;
		while (true) {
			//std::cout << string[i]<<'\n';
			if (string[i] == a.string[counter]) {
				//std::cout <<'a'<< a.string[i] << '\n';
				if (a.string[counter] == '\0') {
					return i - counter;
				}
				counter++;
			}
			else {
				counter = 0;
			}
			if (string[i] == '\0') {
				return -1;
			}

			i++;
		}
	};
	int findstring(char* a) {
		int i = 0;
		int counter = 0;
		while (true) {
			if (string[i] == a[counter]) {
				if (a[counter] == '\0') {
					return i - counter;
				}
				counter++;
			}
			else {
				counter = 0;
			}
			if (string[i] == '\0') {
				return -1;
			}

			i++;
		}
	};
	/*int findstring(cutotterstring a) {
		int i = 0;
		int counter = 0;
		while (true) {
			if (string[i] == '\0') {
				return -1;
			}
			if (string[i] == (*a.pointer).string[counter]) {
				counter++;
				if (counter == a.len) {
					return i - counter + 1;
				}
			}
			else {
				counter = 0;
			}
			i++;
		}
	};*/
	void addell(char a) {
		int len = len1(string);
		char* string2 = new char[len + 2];
		for (int i = 0; i < len; i++) {
			string2[i] = string[i];
		}
		string2[len] = a;
		string2[len+1] = '\0';
		delete[] string;
		string = string2;
	};
};

class cutotterstring {
public:
	otterstring* pointer = nullptr;
	int pos = 0;
	int len = 0;
	cutotterstring(otterstring& pointer1, int len1 = 1, int pos1 = 0) {
		pointer = &pointer1;
		pos = pos1;
		len = len1;
	}
	void print() {
		for (int i = 0; i < len; i++) {
			std::cout << (*pointer).string[i+pos] << ',';
		}
		std::cout << '\n';
	}
};
