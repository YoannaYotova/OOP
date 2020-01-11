#pragma once
#include"Product.h"
#include<iostream>
using namespace std;

class Store
{
	int capacity;
	int size; // size_t
	Product * products = nullptr;

	void expand();
	int find(const char* SKU);
public:
	Store();          
	Store(const Store& cpy);
	Store& operator=(const Store& cpy);
	~Store();   

	void addProduct(const Product& product);
	void removeProduct(const char* SKU);
	void changeProduct(const char* SKU,const char* newSKU);

	Product& operator[](int index);
	friend ostream& operator<<(ostream& os, Store& p);
	void print();

};

