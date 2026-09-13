#pragma once
#include <iostream>
using namespace std;

class Phone {
	string model;
	string date;
public:
	Phone();
	Phone(string model1, string mate1);
	void Init(string model1, string date1);
	void printInfo() const;

	string getModel() const;
	string getDate() const;
	void setModel(string model1);
	void setDate(string date1);
};


class Student
{
	string name;
	string group;
	string spec;
public:
	Student();
	Student(string name1, string group1, string spec1);
	void Init(string name1, string group1, string spec1);
	void printStudent() const;
	void changeGroup(string newGroup);

	string getName() const;
	string getGroup() const;
	string getSpec() const;
	void setName(string name1);
	void setGroup(string group1);
	void setSpec(string spec1);
};


class User
{
	string login;
	string email;
	string password;
public:
	User();
	User(string login1, string email1, string password1);
	void Init(string login1, string email1, string password1);
	void showProfile() const;
	void changePassword(string password1, string newpassword);
	void changePasswordManual();

	string getLogin() const;
	string getEmail() const;
	void setLogin(string login1);
	void setEmail(string email1);
	void setPassword(string password1);
};