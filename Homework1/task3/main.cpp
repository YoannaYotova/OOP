#include<iostream>
#include<Windows.h>
#include"Product.h"
#include"Store.h"
using namespace std;

int main()
{
	Product a, b, c;
	Store myStore;
	char ch;
	cout << "Manu for the SNEAKERS' characteristcs: " << endl;
	cout << "A   Add new product" << endl;
	cout << "X   Delete product" << endl;
	cout << "C   Change product" << endl;
	cout << "D   Display products" << endl;
	cout << "Q   Quit" << endl;
	do
	{
		cout << "Ender a letter from the menu: ";
		cin >> ch;
		switch (ch)
		{
		case'A':
		{
			cin >> a;
			myStore.addProduct(a);
		}break;
		case'X':
		{
			char a[100];
			cout << "enter the product by SKU you want to delete: ";
			cin >> a;
			myStore.removeProduct(a);
		}break;
		case 'C':
		{
			char a[100];
			char b[100]; 
			cout << "enter the SKU\nyou want to change: ";
			cin >> a;
			cout << "enter the SKU\nyou want to change with: ";
			cin >> b;
			myStore.changeProduct(a, b);
		}break;
		case'D': cout << myStore << endl; break;
		case'Q': return 0; break;
		default: cout << "Wrong input!\n"; system("pause"); break;
		}

	} while (true);
	
	system("pause");
	return 0;
}