#pragma once
#include"User.h"
class PowerUser: public User
{
protected:
	int reputation = 0;
public:
	PowerUser();
	PowerUser(const char* ip, const char* username, const char* pass, const char* title,int reputation);
	
	void reputationPlusOne(const User& user);
	void print() const;
};


