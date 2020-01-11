#pragma once

struct DNSRecord
{
	char* domainName = nullptr;
	char* ipAddress = nullptr;
	
	void setDomainName(const char* domainName);
	void setIpAddress(const char* ipAddress);

	DNSRecord();
	DNSRecord(const DNSRecord& cpy);
	DNSRecord& operator=(const DNSRecord& cpy);

	~DNSRecord();
};

class DNSCache
{
	int size;
	int capacity;
	DNSRecord* elements;

	void expand();
public:
	
	DNSCache();
	DNSCache(const DNSCache& cpy);
	DNSCache& operator=(const DNSCache& cpy);
	~DNSCache();

	
	void add(const DNSRecord& el);
	const char* lookup(const char* name)const;
	void flush();
	void print() const;
};

