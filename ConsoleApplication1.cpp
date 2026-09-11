// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


static void myqsort(vector<int>& arr,int max,int min) {
    int mid = arr[max];
    int st = min;
    int en = max - 1;
    if(max-min>1){
    for (int i = min;i < max-1;i++) {

        if (arr[st] < mid) {
            st++;
        }
        else if(arr[en] >= mid){
            en--;
        }
        else {
            swap(arr[st], arr[en]);
            i--;
        }
        if(st == en) {
            swap(arr[st], arr[max]);
            myqsort(arr, max,st);
            myqsort(arr, st-1,min);
            
        }
    }
    }
    else {
        if (arr[max] < arr[min]) {
            swap(arr[max], arr[min]);
        }

    }
}

int main()
{
    vector<int> arr;
    int size = 10;
    for (int i = 0;i < size;i++) {
        arr.push_back(rand() % 100);
    }
    for (int i = 0;i < size;i++) {
        cout << arr[i]<<' ';
    }
    cout << endl;
    myqsort(arr, size - 1, 0);
        for (int i = 0;i < size;i++) {
            cout << arr[i] << ' ';
        }
    cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
