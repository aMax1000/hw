#pragma once

#include <iostream>
#include <bitset>
#include <utility>
using namespace std;

template <typename T>
class otterbranch {
	otterbranch(){
		otterbranch* firstpointer=nullptr;
		otterbranch* lastpointer = nullptr;
		bitset<1> hasEl = 0;
		signed int size = 0;
		vector<bool> memory = {1,0,1};
	}
	T ell;
	void addmemory() {

	}
	void check(bitset a,int& point){
		if (size == 0) {
			if ((a << point) % 2 == 1) {
				return check(firstpointer, ++point)
			}
			else {
				return check(lastpointer, ++point)
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				++point
				if()
			}
		}
	}
};

class ottertree {
	public:
		ottertree(){

		}
		template <typename T1, typename T2>
		void addel(pair<T1,T2> el) {
			bitset < sizeof(T1) >= el.first;
			for (int i = 0; i < sizeof(T1); i++) {

			}
		}
};