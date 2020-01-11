#pragma once
#include <iostream>
using namespace std;
// the product is a pear of sneakers
class Product 
{
	char* SKU = nullptr;     //123456
	char* brand = nullptr;   //Nike
	char* model = nullptr;  //AirMax
	char* colour = nullptr; //Black

	float price; //230.99
	int count; //130
	double size; //36

public:
	Product();
	Product(const char* SKU, const char* brand, const char* model,const char* colour, float price, int count,double size);
	Product(const Product& cpy);
	Product& operator= (const Product& cpy);
	~Product();

	void setSKU(const char* SKU);
	void setBrand(const char* Brand);
	void setModel(const char* model);
	void setColour(const char* colour);
	void setPrice(float price);
	void setCount(int count);
	void setSize(double size);

	const char* getSKU() const;
	const char* getBrand() const;
	const char* getModel()const;
	const char* getColour()const;
	float getPrice()const;
	int getCount()const;
	double getSize() const;

	friend ostream& operator<<(ostream& os, const Product& p);
	friend istream& operator>>(istream& is, Product& p);

	void printTheInfo() const;
};

