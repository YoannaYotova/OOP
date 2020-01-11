#include "DNSCache.h"
#include<cstring>
#include<iostream>
#include<ostream>

using namespace std;

//struct DNSRecord:

void DNSRecord::setDomainName(const char * domainName)
{
	delete[] this->domainName;
	int length = strlen(domainName) + 1;
	this->domainName = new char[length];
	strcpy_s(this->domainName, length, domainName);
}

void DNSRecord::setIpAddress(const char * ipAddress)
{
	delete[]this->ipAddress;
	int length = strlen(ipAddress) + 1;
	this->ipAddress = new char[length];
	strcpy_s(this->ipAddress, length, ipAddress);
}

DNSRecord::DNSRecord()
{
	setDomainName(" ");
	setIpAddress(" ");
}

DNSRecord::DNSRecord(const DNSRecord & cpy)
{
	setDomainName(cpy.domainName);
	setIpAddress(cpy.ipAddress);
}

DNSRecord & DNSRecord::operator=(const DNSRecord & cpy)
{
	if (this != &cpy)
	{
		setDomainName(cpy.domainName);
		setIpAddress(cpy.ipAddress);
	}
	return *this;
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	delete[] ipAddress;
}


//class DNSCache:

void DNSCache::expand()
{
	capacity *= 2;
	DNSRecord* tmp = new DNSRecord[capacity];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = elements[i];
	}
	delete[size] elements;
	elements = tmp;
}

DNSCache::DNSCache(): size(0), capacity(8)
{
	elements = new DNSRecord[capacity];
}

DNSCache::DNSCache(const DNSCache & cpy): size(cpy.size), capacity(cpy.capacity)
{
	elements = new DNSRecord[capacity];
	for (size_t i = 0; i < size; i++)
	{
		elements[i] = cpy.elements[i];
	}
}

DNSCache & DNSCache::operator=(const DNSCache & cpy)
{
	if (this != &cpy)
	{
		delete[capacity] elements;

		size = cpy.size;
		capacity = cpy.capacity;
		elements = new DNSRecord[capacity];
		for (size_t i = 0; i < size; i++)
		{
			elements[i] = cpy.elements[i];
		}
	}
	return *this;
}


DNSCache::~DNSCache()
{
	delete[capacity] elements;
}

void DNSCache::add(const DNSRecord & el)
{
	if (size == capacity)
	{
		expand();
	}
	elements[size] = el;
	size++;
}

const char* DNSCache::lookup(const char* domainName) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(domainName, elements[i].domainName) == 0)
			return elements[i].ipAddress ;
	}
	return nullptr;
}

void DNSCache::flush()
{
	size = 0;
	cout << "No elements" << endl;
}

void DNSCache::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << " Domain name: " << elements[i].domainName;
		cout<<" IP address: " << elements[i].ipAddress;
		cout << endl;
	}
}




