#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct ValueMoney
{
    int value;
    int amout;
}; 


class Bancomat {
    int id;
    vector<ValueMoney> valuemoney;
    int min;
    int max;

public:
    // Constructors
    Bancomat(int id, vector<ValueMoney> valuemoney, int min, int max);

    // Init functions
    void Init(int id, vector<ValueMoney> valuemoney, int min = 0, int max = 0);

    // Getters
    int GetId() const;
    vector<ValueMoney> GetMoney() const;
    int GetMin() const;
    int GetMax() const;

    // Setters
    void SetId(int id);
    void SetMoney(vector<ValueMoney> a);
    void SetMoneyI(int i,ValueMoney a);
    void SetMin(int min);
    void SetMax(int max);

    
    void Deposit(vector<int> a);
    int Deposit(int money);
    int Withdraw(int money);
    void Print() const;
};
