#include "User.h"
#include<cstring>
#include<iostream>
using namespace std;


void User::encryptedPassword(const char * Password, char* buff)
{
	
	int length = strlen(Password) + 1;
	for (int i = 0; i < length; i++)
	{
		buff[i] = Password[i] + 10; //buff is the encrypted password
	}
}

void User::setUsername(const char * usename)
{
	int lenght = strlen(usename) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, usename);
	delete[] Username;
	Username = tmp;
}

void User::setTitle(const char * title)
{
	int lenght = strlen(title) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, title);
	delete[] Title;
	Title = tmp;
}

User::User()
{
	setUsername("");
	setPassword("");
	setTitle("");
}

User::User(const char * ip, const char * username, const char * pass, const char * title):Guest(ip)
{
	setUsername(username);
	setPassword(pass);
	setTitle(title);
}

User::User(const User & cpy):Guest(cpy)
{
	setUsername(cpy.Username);
	setPassword(cpy.Password);

}

User & User::operator=(const User & cpy)
{
	if (this != &cpy)
	{
		Guest::operator=(cpy);
		setUsername(cpy.Username);
		setPassword(cpy.Password);
		setTitle(cpy.Title);
	}
	return *this;


}

User::~User()
{
	delete[] Username;
	delete[] Password;
	delete[] Title;
}

void User::setPassword(const char * pass)
{
	int lenght = strlen(pass) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, pass);
	delete[] Password;
	Password = tmp;
}

void User::changePassword(const char * Pass,const char * newPass)
{
	if (Pass = Password)
	{
		setPassword(newPass);
	}
}

const char * User::getUsername() const
{
	return Username;
}

void User::print() const
{
	cout << IPAddress << " " << Username << " " << Password << " " << Title;

}
