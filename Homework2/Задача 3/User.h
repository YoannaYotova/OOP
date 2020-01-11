#pragma once
#include"Guest.h"

class User:public Guest
{
protected:
	char* Username = nullptr;
	char* Password = nullptr;
	char* Title = nullptr;

	void encryptedPassword(const char* Password, char* buff);

private:
	void setUsername(const char* username);
	void setTitle(const char* title);

public:
	User();
	User(const char* ip, const char* username, const char* pass, const char* title);
	User(const User& cpy);
	User& operator=(const User& cpy);
	~User();

	void setPassword(const char* pass);
	void changePassword(const char* oldPass,const char* newPass);

	const char* getUsername()const;
	void print() const ;

	friend class Admin;
};

