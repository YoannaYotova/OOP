#include<iostream>
#include <cstdlib>
#include<ctime>
#include"MagicBox.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	MagicBox<int> A;

	A.insert(3);
	A.insert(13);
	A.insert(34);
	A.insert(5); 
	A.insert(23);
	A.insert(99);

	A.pop();
	A.list();

	system("pause");
}
