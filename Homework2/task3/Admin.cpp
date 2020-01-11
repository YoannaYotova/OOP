#include "Admin.h"
#include<cstring>


Admin::Admin(): PowerUser(), VIP()
{
}

void Admin::setUsername(const char * username)
{
	int lenght = strlen(username) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, username);
	delete[]User:: Username;
	User::Username = tmp;
}

void Admin::changeAnotherUsername(User & user, const char * newUsername)
{
	int lenght = strlen(newUsername) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, newUsername);
	delete[] user.Username;
	user.Username = tmp;
}

