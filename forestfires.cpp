// forestfires.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <utility>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <set>
#include <unordered_set>
#include "basicslib.h"
#include "safepixels0-2.h"
using namespace std;


char fire(char a) {
    return 'G';
}
bool istree(char a) {
    return (a == 'T');
}
char treegrow(vector<pair<int, int>>& uns, int i, int j) {
    if (!(rand()%100)) {
        
        if (!(rand() % 30)) {
            return 'F';
            uns.push_back({i,j});
        }
        else {
            return 'T';
        }
    }
    else {
        return ' ';
    }
}
char air(char a) {
    return ' ';
}
void printboard(char** arr,int col,int row) {
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if (arr[i][j] == 'F') {
                SetColor(12, 0);
                std::cout << 'F';
                SetColor(7, 0);
            }
            else if (arr[i][j] == 'T') {
                SetColor(2, 0);
                std::cout << 'T';
                SetColor(7, 0);
            }
            else {
                cout << arr[i][j];
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
int main()
{
    
    vector<pair<int, int>> updateset;
    vector<pair<int, int>> newupdateset;
    funcarr a;
    a.addell(fire,1,0, true, istree);
    a.addell(fire, 0, -1, true, istree);
    a.addell(fire, 0, 1, true, istree);
    a.addell(fire, -1, 0,true,istree);
    a.addell(air, 0, 0, false);
    int row = 20;
    int col = 20;
    char** board = new char* [col];
    for (int i = 0; i < col; i++) {
        board[i] = new char[col];
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            board[i][j] = ' ';
        }
    }
    while (true) {
        update(board, col, row, 'F',updateset, newupdateset, a);
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if(board[i][j]==' '){
                board[i][j] = treegrow(newupdateset,i,j);
                if (board[i][j] == 'F') {
                    newupdateset.push_back({ i, j });
                }
                }else if(board[i][j] == 'G') {
                    board[i][j] = 'F';
                }
            }
        }
        
        printboard(board, col, row);
        for (int i = 0; i < col; i++) {
            cout << "--";
        }
        cout << endl;
        //print(newupdateset);
        updateset.clear();
        updateset = newupdateset;
        newupdateset.clear();
        //print(updateset);
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    for (int i = 0; i < col; i++) {
        delete[] board[i];
    }
    delete[] board;
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
