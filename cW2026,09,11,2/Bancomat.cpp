
#pragma once
#include "Bancomat.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

Bancomat::Bancomat(int id, vector<ValueMoney> valuemoney, int min, int max)
    : id(id), 
    valuemoney(valuemoney),
    min(min), 
    max(max)

{
}

void Bancomat::Init(int id, vector<ValueMoney> valuemoney, int min, int max )
{
    this->id = id;
    for (ValueMoney a : valuemoney) {
        this->valuemoney.push_back(a);
    }
    this->min = min;
    this->max = max;
}

int Bancomat::GetId() const
{
    return id;
}

vector<ValueMoney> Bancomat::GetMoney() const
{
    return valuemoney;
}


int Bancomat::GetMin() const
{
    return min;
}

int Bancomat::GetMax() const
{
    return max;
}

void Bancomat::SetId(int id)
{
    this->id = id;
}

void Bancomat::SetMoney(vector<ValueMoney> a)
{
    this->valuemoney = a;
}
void Bancomat::SetMoneyI(int i,ValueMoney a)
{
    this->valuemoney[i] = a;
}


void Bancomat::SetMin(int min)
{
    this->min = min;
}

void Bancomat::SetMax(int max)
{
    this->max = max;
}

void Bancomat::Deposit(vector<int> a)
{
    int sum=0;
    for (int i = 0;i < a.size();i++) {
        sum += a[i]*this->valuemoney[i].value;
    }

    if(sum <=this->max and sum >= this->min){
        for (int i = 0;i < a.size();i++) {
            this->valuemoney[i].amout += a[i];
        }
    }
    else {
        cout << "NOT IN LIMITS" << endl;
    }
}

int Bancomat::Deposit(int money)
{
    int money1 = money;
    if(money1<=this->max and money1 >= this->min){
        for (int i = 0; i < this->valuemoney.size();i++) {
            this->valuemoney[i].amout += money1 / this->valuemoney[i].value;
            money1 %= this->valuemoney[i].value;
        }
    }
    else {
        cout << "NOT IN LIMITS" << endl;
    }
    return money1;
}
int Bancomat::Withdraw(int money)
{
    int money1 = money;
    if (money1 <= this->max and money1 >= this->min) {
        for (int i = 0; i < this->valuemoney.size();i++) {
            if (money1 / this->valuemoney[i].value > this->valuemoney[i].amout) {
                money1 - this->valuemoney[i].value * this->valuemoney[i].amout;
                this->valuemoney[i].amout = 0;
                cout << "not enougth banknotes of value: " << this->valuemoney[i].value;
            }
            else {
                this->valuemoney[i].amout -= money1 / this->valuemoney[i].value;
                money1 %= this->valuemoney[i].value;
            }
        }
    return money1;
}

void Bancomat::Print() const
{
    std::cout << std::left;

    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "id:" << id << std::endl;
    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "money1000:" << money1000 << std::endl;
    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "money100:" << money100 << std::endl;
    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "money10:" << money10 << std::endl;
    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "min:" << min << std::endl;
    std::cout << std::setw(7 + floor(log10(this->valuemoney[0].value))) << "max:" << max << std::endl;
}

