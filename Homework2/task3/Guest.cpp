#include "Guest.h"
#include<cstring>


Guest::Guest()
{
	setIPAddress("");
}

Guest::Guest(const char * ipaddress)
{
	setIPAddress(ipaddress);
}

Guest::Guest(const Guest & cpy)
{
	setIPAddress(cpy.IPAddress);
}

Guest & Guest::operator=(const Guest & cpy)
{
	if (this != &cpy)
	{
		setIPAddress(cpy.IPAddress);
	}
	return*this;
}

Guest::~Guest()
{
	delete[] IPAddress;
}

const char * Guest::getIPAddress() const
{
	return this->IPAddress;
}

void Guest::setIPAddress(const char * ipaddress)
{
	int lenght = strlen(ipaddress) + 1;
	char* tmp = new char[lenght];
	strcpy_s(tmp, lenght, ipaddress);
	delete[] IPAddress;
	IPAddress = tmp;
}
