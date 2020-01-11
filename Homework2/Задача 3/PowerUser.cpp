#include"PowerUser.h"
#include<cstring>
#include<iostream>
using namespace std;


PowerUser::PowerUser()
{
	reputation = -1;
}

PowerUser::PowerUser(const char * ip, const char * username, const char * pass, const char * title, int reputation):
	User(ip,username,pass,title)
{
	this->reputation = reputation;
}

void PowerUser::reputationPlusOne(const User & user)
{
	if (strcmp(this->Username,user.getUsername())!=0)reputation += 1;
}

void PowerUser::print() const
{
	User::print();
	cout <<" "<< reputation<<endl;
}



