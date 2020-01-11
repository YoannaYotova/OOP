#pragma once
#include"VIP.h"
#include "PowerUser.h"
class Admin: public VIP, public PowerUser
{
public:
	Admin();
	
	void setUsername(const char*);
	void changeAnotherUsername(User& user, const char* newUsername);
};

