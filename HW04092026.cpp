#include <iostream>
using namespace std;

class book {
	string name="";
	string autor="";
	signed int pageNumbers=0;
public:
	void PrintInfo() {
		cout << "Book Name: " << name<<'\n';
		cout << "Autor: " << autor << '\n';
		cout << "Number Of Pages: " << pageNumbers << '\n';
	}
    string getname() {
        return name;
    }

    string getautor() {
        return autor;
    }

    signed int getpageNumbers() {
        return pageNumbers;
    }

    void setname(string a) {
        name = a;
    }

    void setautor(string a) {
        autor = a;
    }

    void setpageNumbers(signed int a) {
        pageNumbers = a;
    }

    void Init(string name1, string autor1, signed int pageNumbers1) {
        name = name1;
        autor = autor1;
        pageNumbers = pageNumbers1;
    }

    void Input(){
        cout << "Enter Book Name: " << '\n';
        string name1;
        cin >> name1;
        cout << "Enter Autor: " << '\n';
        string autor1;
        cin >> autor1;
        cout << "Enter Number Of Pages: " << '\n';
        signed int pageNumbers1;
        cin >> pageNumbers1;
        Init(name1, autor1, pageNumbers1);
    }
};

class BankAccount {
    signed int accountNumber = 0;
    string owner = "";
    signed int balance = 0;
public:
    void PrintInfo() {
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Owner: " << owner << '\n';
        cout << "Balance: " << balance << '\n';
    }
    signed int getaccountNumber() {
        return accountNumber;
    }

    string getowner() {
        return owner;
    }

    signed int getbalance() {
        return balance;
    }

    void setaccountNumber(signed int a) {
        accountNumber = a;
    }

    void setowner(string a) {
        owner = a;
    }

    void setbalance(signed int a) {
        balance = a;
    }

    void Init(signed int accountNumber1, string owner1, signed int balance1) {
        accountNumber = accountNumber1;
        owner = owner1;
        balance = balance1;
    }

    void Input() {
        cout << "Enter Number: " << '\n';
        signed int accountNumber1;
        cin >> accountNumber1;
        cout << "Enter owner: " << '\n';
        string owner1;
        cin >> owner1;
        cout << "Enter Balance: " << '\n';
        signed int balance1;
        cin >> balance1;
        Init(accountNumber1, owner1, balance1);
    }

    void addToBalance(signed int a) {
        balance += a;
    }

    bool Withdraw(signed int a) {
        if (a <= balance) {
            balance -= a;
            cout << "Successful Withdrawal\n";
            return 1;
        }
        else {
            cout << "Not Enough On The Balance To Withdraw\n";
            return 0;
        }
    }

    signed int WithdrawAll() {
        signed int a = balance;
        balance = 0;
        return a;
    }
};

int main() {
    book myBook;

    myBook.Init("Harry Potter", "Rowling", 500);

    myBook.PrintInfo();

    cout << '\n';

    cout << "Name: " << myBook.getname() << '\n';
    cout << "Autor: " << myBook.getautor() << '\n';
    cout << "Pages: " << myBook.getpageNumbers() << '\n';

    myBook.setname("TheHobbit");
    myBook.setautor("Tolkien");
    myBook.setpageNumbers(310);

    cout << '\n';

    myBook.PrintInfo();

    cout << '\n';

    myBook.Input();

    cout << '\n';

    myBook.PrintInfo();

    cout << '\n';



    BankAccount account;

    account.Init(12345, "Alex", 1000);

    account.PrintInfo();

    cout << '\n';

    cout << "Account Number: " << account.getaccountNumber() << '\n';
    cout << "Owner: " << account.getowner() << '\n';
    cout << "Balance: " << account.getbalance() << '\n';

    account.setaccountNumber(54321);
    account.setowner("John");
    account.setbalance(2000);

    cout << '\n';

    account.PrintInfo();

    account.addToBalance(500);

    cout << '\n';

    account.PrintInfo();

    cout << '\n';

    account.Withdraw(700);
    account.PrintInfo();

    cout << '\n';

    account.Withdraw(5000);
    account.PrintInfo();

    cout << '\n';

    signed int withdrawn = account.WithdrawAll();

    cout << "Withdrawn amount: " << withdrawn << "\n\n";
    account.PrintInfo();

    cout << '\n';

    account.Input();

    cout << '\n';

    account.PrintInfo();

    return 0;
}