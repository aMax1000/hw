#pragma once
#include <iostream>
#include <utility>
#include <Windows.h>
#include <set>
#include <unordered_set>
#include "basicslib.h"
using namespace std;

bool truec(char a) {
    return true;
}

typedef char (*ctocf)(char);
typedef bool (*conditionchar)(char);
struct func2d {
    conditionchar condition;
    ctocf func;

};
struct funcarr {
    pair<pair<conditionchar,pair<ctocf,bool>>, pair<int, int>>* arr = new pair<pair<conditionchar, pair<ctocf, bool>>, pair<int, int>>[1];
    int size1 = 0;
    ~funcarr() {
        delete[] arr;
    }
    void addell(ctocf func, int x, int y, bool toupdate=true,conditionchar condition=truec) {
        resize(arr, size1, size1 + 1);
        pair<pair<conditionchar, pair<ctocf, bool>>, pair<int, int>> a;
        a.first.first = condition;
        a.first.second.first = func;
        a.first.second.second = toupdate;
        a.second.first = x;
        a.second.second = y;
        arr[size1] = a;
        size1++;
    }
    int size() {
        return size1;
    };
    int x(int i) {
        if (i < size1) {
            return (arr[i].second.first);
        }
        else {
            cout << "ERROR OUT OF INDEX X";
        }

    };
    int y(int i) {
        if (i < size1) {
            return (arr[i].second.second);
        }
        else {
            cout << "ERROR OUT OF INDEX Y";
        }
    };
    ctocf func(int i) {
        if (i < size1) {
            return (arr[i].first.second.first);
        }
        else {
            cout << "ERROR OUT OF INDEX FUNC";
        }
    };
    conditionchar cond(int i) {
        if (i < size1) {
            return (arr[i].first.first);
        }
        else {
            cout << "ERROR OUT OF INDEX COND";
        }
    };
    bool doupdate(int i) {
        if (i < size1) {
            return (arr[i].first.second.second);
        }
        else {
            cout << "ERROR OUT OF INDEX DOUPDATE";
        }
    };
};

template<typename T>
void saferunup(T**& arr, int col, int row, int x, int y, funcarr& a, vector<pair<int, int>>& newupdateset) {
    int d = a.size();
    for (int i = 0; d > i; i++) {
        if (not(((a.x(i) + x >= col) or (a.y(i) + y >= row)) or ((a.x(i) + x < 0) or (a.y(i) + y < 0)))) {
            if(a.cond(i)(arr[x + a.x(i)][y + a.y(i)])){
                arr[x + a.x(i)][y + a.y(i)] = a.func(i)(arr[x + a.x(i)][y + a.y(i)]);
                if(a.doupdate(i)){
                    newupdateset.push_back({ (x + a.x(i)),(y + a.y(i))});
                }
            }
        }
    }
    return;
}


bool update(char**& arr, int col, int row, char target,vector<pair<int, int>> updateset, vector<pair<int, int>>& newupdateset, funcarr& funcarr) {
    bool a = false;
    for (pair<int, int> n : updateset) {
        if(arr[n.first][n.second]==target){
            saferunup(arr, col, row, n.first, n.second, funcarr,newupdateset);
        }
    }
    return a;
}





template<typename T>
void saferun(T**& arr, int col, int row, int x, int y, funcarr& a) {
    int d = a.size();
    for (int i = 0; d > i; i++) {
        if (not(((a.x(i) + x >= col) or (a.y(i) + y >= row)) or ((a.x(i) + x < 0) or (a.y(i) + y < 0)))) {
            if (a.cond(i)) {
                arr[x + a.x(i)][y + a.y(i)] = a.func(i)(arr[x + a.x(i)][y + a.y(i)]);
            }
        }
    }
    return;
}
bool scanfor(char**& arr, int col, int row, char target, funcarr& func) {
    bool a = false;
    for (int i = 0; col > i; i++) {
        for (int j = 0; row > j; j++) {
            if (arr[i][j] == target) {
                a = true;
                saferun(arr, col, row, i, j, func);
            }
        }
    }
    return a;
}
