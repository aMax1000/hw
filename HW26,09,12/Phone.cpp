#include "Phone.h"
Phone::Phone()
{
	model = "";
	date = "";
}
Phone::Phone(string Model1, string Date1)
{
	model = Model1;
	date = Date1;
}
void Phone::Init(string Model1, string Date1)
{
	model = Model1;
	date = Date1;
}
void Phone::printInfo() const
{
	cout << "Model: " << model << "\nDate: " << date << '\n';
}

void Phone::setModel(string Model)
{
	model = Model;
}
string Phone::getModel() const
{
	return model;
}

void Phone::setDate(string Date)
{
	date = Date;
}
string Phone::getDate() const
{
	return date;
}




Student::Student()
{
	name = "";
	group = "";
	spec = "";
}

Student::Student(string name1, string group1, string spec1)
{
	name = name1;
	group = group1;
	spec = spec1;
}

void Student::Init(string name1, string group1, string spec1)
{
	name = name1;
	group = group1;
	spec = spec1;
}

void Student::printStudent() const
{
	cout << "Name: " << name << "\nGroup: " << group
		<< "\nSpeciality: " << spec << '\n';
}

void Student::changeGroup(string group1)
{
	if (group1 != "") {
		group = group;
	}
	else {
		cout << "INVALID GROUP\n";
	}
}

void Student::setName(string name1)
{
	name = name1;
}

void Student::setGroup(string group1)
{
	group = group1;
}

void Student::setSpec(string spec1)
{
	spec = spec1;
}

string Student::getName() const
{
	return name;
}

string Student::getGroup() const
{
	return group;
}

string Student::getSpec() const
{
	return spec;
}


User::User()
{
	login = "";
	email = "";
	password = "";
}

User::User(string login1, string email1, string password1)
{
	login = login1;
	email = email1;
	password = password1;
}

void User::Init(string login1, string email1, string password1)
{
	login = login1;
	email = email1;
	if(password1!="-1"){
	password = password1;
	}
	else {
		cout << "PROHIBITED PASSWORD CHANGING TO 0";
		password = "0";
	}
}

void User::showProfile() const
{
	cout << "Login: " << login << "\nEmail: " << email << '\n';
}

void User::changePassword(string password1, string newpassword)
{
	if (password1 == password) {
		this->setPassword(newpassword);
	}
}

void User::changePasswordManual()
{
	string password1;
	string newpassword;
	cout << "print old password:\n";
	do {
		cin >> password1;
		if (password1 == password) {
			cout << "print new password:\n";
			cin >> newpassword;
			this->setPassword(newpassword);
			return;
		}
		else {
			cout << "Incorrrect old password type -1 to exit\n";
		}
	} while (password1!="-1");
}

void User::setLogin(string login1)
{
	login = login1;
}

void User::setEmail(string email1)
{
	email = email1;
}

void User::setPassword(string password1)
{
	if (password1 != "-1") {
		password = password1;
	}
	else {
		cout << "PROHIBITED PASSWORD\n";
	}
}

string User::getLogin() const
{
	return login;
}

string User::getEmail() const
{
	return email;
}