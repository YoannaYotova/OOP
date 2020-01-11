#include "Store.h"
#include<cstring>
#include<iostream>
using namespace std;

void Store::expand()
{
	capacity *= 2;
	Product* tmp = new Product[capacity];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = products[i];
	}
	delete[] products;
	products = tmp;
	
}

int Store::find(const char * SKU)
{
	for (size_t i = 0; i < size; i++)
	{
		if(strcmp(SKU,products[i].getSKU())==0)
			return i;
	}
	return -1;
}

Store::Store(): capacity(8), size(0)
{
	products = new Product[capacity];
}

Store::Store(const Store & cpy):capacity(cpy.capacity),size(cpy.size)
{
	products = new Product[capacity];
	for (size_t i = 0; i < size; i++)
	{
		products[i] = cpy.products[i];
	}
}

Store & Store::operator=(const Store & cpy)
{
	if (this != &cpy)
	{
		delete[] products;

		capacity = cpy.capacity;
		size = cpy.size;

		products = new Product[capacity];
		for (size_t i = 0; i < size; i++)
		{
			products[i] = cpy.products[i];
		}
	}
	return *this;
}

Store::~Store()
{
	delete[] products;
}

void Store::addProduct(const Product & product)
{
	if (find(product.getModel()) >= 0)
		return;
	if (size == capacity)
	{
		expand();
	}
	products[size] = product;
	size++;
}

void Store::removeProduct(const char * SKU)
{
	int index = find(SKU);
	if (index < 0)return;
	products[index] = products[size - 1];
	size--;
}

void Store::changeProduct(const char * SKU,const char* newSKU)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(SKU, products[i].getSKU()) == 0)products[i].setSKU(newSKU);
	}
	return;
}

Product & Store::operator[](int index)
{
	return products[index];
}

void Store::print()
{

	for (size_t i = 0; i < size; i++)
	{
		products[i].printTheInfo();
		cout << endl;
	}
}

ostream & operator<<(ostream & os, Store & p)
{
	for (size_t i = 0; i < p.size; i++)
	{
		os << p[i]<<endl;
	}
	return os;
}
