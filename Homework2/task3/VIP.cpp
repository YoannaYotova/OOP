#include "VIP.h"
#include<cstring>


VIP::VIP(): User()
{
}

VIP::VIP(const char * ip, const char * username, const char * pass, const char * title):
	User(ip, username, pass, title)
{
}


void VIP::setTitle(const char * title)
{
	int lenght = strlen(title) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, title);
	delete[] Title;
	Title = tmp;
}

void VIP::print() const
{
	User::print();
}
