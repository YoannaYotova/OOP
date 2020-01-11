#pragma once
class Guest
{
protected:

	char* IPAddress = nullptr;

public:
	Guest();
	Guest(const char* ipaddress);
	Guest(const Guest& cpy);
	Guest& operator=(const Guest& cpy);
	~Guest();

	const char* getIPAddress() const;
	void setIPAddress(const char* ipaddress);
};

