#include<iostream>
#include "DNSCache.h"
#include<Windows.h>

using namespace std;

int main()
{
	DNSRecord a, b;
	a.setDomainName("Yoanna");
	a.setIpAddress("234567");
	b.setDomainName("Aleks");
	b.setIpAddress("567432");

	DNSCache A;
	A.add(a);
	A.add(b);
	A.print();

	cout <<"The IP Address by domain name Yoanna: "<< A.lookup("Yoanna") << endl;

	A.flush();
	A.print();
	A.add(b);
	A.print();


	system("pause");
	return 0;
}