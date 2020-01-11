#include "Product.h"
#include<cstring>
#include<iostream>
using namespace std;


Product::Product():price(0), count(0),size(0)
{
	setSKU(" ");
	setBrand(" ");
	setModel(" ");
	setColour(" ");
}

Product::Product(const char * SKU, const char * brand, const char * model,const char* colour, float price, int count,double size):
	price(price), count(count),size(size)
{
	setSKU(SKU);
	setBrand(brand);
	setModel(model);
	setColour(colour);
}

Product::Product(const Product & cpy):price(cpy.price), count(cpy.count),size(cpy.size)
{
	setSKU(cpy.SKU);
	setBrand(cpy.brand);
	setModel(cpy.model);
	setColour(cpy.colour);
}

Product & Product::operator=(const Product & cpy)
{
	if (this != &cpy)
	{
		price = cpy.price;
		count = cpy.count;
		size = cpy.size;
		setSKU(cpy.SKU);
		setBrand(cpy.brand);
		setModel(cpy.model);
		setColour(cpy.colour);
	}
	return *this;
}


Product::~Product()
{
	delete[] SKU;
	delete[] brand;
	delete[] model;
	delete[] colour;
}

void Product::setSKU(const char* SKU)
{
	delete[] this->SKU;
	int length = strlen(SKU) + 1;
	this->SKU = new char[length];
	strcpy_s(this->SKU, length, SKU);
}

void Product::setBrand(const char* brand)
{
	delete[] this->brand;
	int length = strlen(brand) + 1;
	this->brand = new char[length];
	strcpy_s(this->brand, length, brand);
}

void Product::setModel(const char * model)
{
	delete[] this->model;
	int length = strlen(model) + 1;
	this->model = new char[length];
	strcpy_s(this->model, length, model);
}

void Product::setColour(const char * colour)
{
	delete[] this->colour;
	int length = strlen(colour) + 1;
	this->colour = new char[length];
	strcpy_s(this->colour, length, colour);
}

void Product::setPrice(float price)
{
	this->price = price;
}

void Product::setCount(int count)
{
	this->count = count;
}

void Product::setSize(double size)
{
	this->size = size;
}

const char * Product::getSKU() const
{
	return SKU;
}

const char * Product::getBrand() const
{
	return brand;
}

const char * Product::getModel() const
{
	return model;
}

const char * Product::getColour() const
{
	return colour;
}

float Product::getPrice() const
{
	return price;
}

int Product::getCount() const
{
	return count;
}

double Product::getSize() const
{
	return size;
}

void Product::printTheInfo() const
{
	cout << "The info about the product: " << endl;
	cout << "The stock keeping unit is: " << this->getSKU() << endl;
	cout << "The brand is: " << this->getBrand() << endl;
	cout << "The model is: " << this->getModel() << endl;
	cout << "The colour is: " << this->getColour() << endl;
	cout << "The size is: " << this->getSize() << endl;
	cout << "The count is: " << this->getCount() << endl;
	cout << "The price is: " << this->getPrice() << endl;

}

ostream & operator<<(ostream & os, const Product & p)
{
	os << "The SKU is: " << p.SKU << endl;
	os << "The brand is: " << p.brand << endl;
	os << "The model is: " << p.model << endl;
	os << "The colour is: " << p.colour << endl;
	os << "The size is: " << p.size << endl;
	os << "The count is: " <<p.count << endl;
	os << "The price is: " <<p.price << endl;
	return os;
}

istream & operator>>(istream & is, Product & p)
{
	char buf[1500];
	if (&is == &cin) cout << "enter SKU: ";
	is >> buf;
	p.setSKU(buf);
	if (&is == &cin) cout << "enter brand: ";
	is >> buf;
	p.setBrand(buf);
	if (&is == &cin) cout << "enter model: ";
	is >> buf;
	p.setModel(buf);
	if (&is == &cin) cout << "enter colour: ";
	is >> buf;
	p.setColour(buf);
	if (&is == &cin) cout << "enter price: ";
	is >> p.price;
	if (&is == &cin)cout << "enter a size: ";
	is >> p.size;
	if (&is == &cin)cout << "enter a count in the store: ";
	is >> p.count;
	return  is;
}