#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>

class MagicBox
{
public:
	MagicBox();
	MagicBox(const MagicBox<T>& cpy);
	MagicBox<T>& operator=(const MagicBox<T>& cpy);
	~MagicBox();

	void insert(const T& el);
	void pop();
	void list() const;


private:
	int capacity;
	int size;
	T* elements;

	void expand();
};

template <typename T>
MagicBox<T>::MagicBox(): capacity(8),size(0)
{
	elements = new T[capacity];
}

template<typename T>
inline MagicBox<T>::MagicBox(const MagicBox<T>& cpy):
	capacity(cpy.capacity), size(cpy.size)
{
	elements = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		elements[i] = cpy.elements[i];
	}
}

template<typename T>
inline MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& cpy)
{
	if (this != &cpy)
	{
		delete[] elements;
		capacity = cpy.capacity;
		size = cpy.size;
		elements = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			elements[i] = cpy.elements[i];
		}
	}
	return *this;
}

template <typename T>
MagicBox<T>::~MagicBox()
{
	delete[] elements;
}

template<typename T>
inline void MagicBox<T>::insert(const T & el)
{
	if (size == capacity)
	{
		expand();
	}
	elements[size] = el;
	size++;
}

template<typename T>
inline void MagicBox<T>::pop()
{
	if (size == 0)
	{
		cout << " Empty box!" << endl;
		return;
	}

	int randomIndex = rand() % size;
	elements[randomIndex] = elements[size - 1];
	size--;
}

template<typename T>
inline void MagicBox<T>::list() const
{
	for (int i = 0; i < size; i++)
	{
		cout << elements[i] << " ";
	}

}

template<typename T>
inline void MagicBox<T>::expand()
{
	capacity *= 2;
	T* tmp = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = elements[i];
	}
	delete[] elements;
	elements = tmp;

}
