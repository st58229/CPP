#pragma once
#ifndef INCREASING_COINTAINER_H
#define INCREASING_COINTAINER_H
#include<cstdlib>

template <typename T, int startSize = 5, int increase = 2>
class IncreasingContainer {
private:
	T* _field;
	unsigned _size;
	unsigned _items;
	void increase();	
	bool isNotFull() const;

public:
	IncreasingContainer();
	~IncreasingContainer();	
	void add(const T& o);
	T& operator[](int index);
	T operator[](int index) const;
	unsigned int getItemsLenght() const;
	void add(int index, const T& o);
	void remove(int index);
};

template <typename T, int startSize, int increase>
IncreasingContainer<T, startSize, increase>::IncreasingContainer()
{
	_field = new T[startSize];
	_size = startSize;
	_items = 0;	
}

template <typename T, int startSize, int increase>
IncreasingContainer<T, startSize, increase>::~IncreasingContainer() { delete[] _field; }

template <typename T, int startSize, int increase>
bool IncreasingContainer<T, startSize, increase>::isNotFull() const
{
	if (_items < _size)
	{
		return true;
	}
	return false;
}

template <typename T, int startSize, int increase>
void IncreasingContainer<T, startSize, increase>::increase()
{
	int newSize = _size * increase;
	T* newField = new T[newSize];

	for (int i = 0; i < _size; i++) {
		newField[i] = _field[i];
	}

	delete[] _field;
	_field = newField;
	_size = newSize;
}

template <typename T, int startSize, int increase>
void IncreasingContainer<T, startSize, increase>::add(const T& o)
{
	if (isNotFull())
	{
		_field[_items] = o;
		_items++;
	}
	else 
	{
		increase();
		_field[_items] = o;
		_items++;
	}
}

template <typename T, int startSize, int increase>
T& IncreasingContainer<T, startSize, increase>::operator[](int index)
{
	if (index >= _items) throw std::invalid_argument("Error - operator");
	return _field[index];
}

template <typename T, int startSize, int increase>
T IncreasingContainer<T, startSize, increase>::operator[](int index) const
{
	if (index > _items - 1) throw std::invalid_argument("Error - operator");	
	return _field[index];
}

template <typename T, int startSize, int increase>
unsigned int IncreasingContainer<T, startSize, increase>::getItemsLenght() const { return _items; }

template <typename T, int startSize, int increase>
void IncreasingContainer<T, startSize, increase>::add(int index, const T& o)
{
	if (!isNotFull()) increase();
	if (index > _items) throw std::invalid_argument("Error - add");
	if (index == _items)
	{
		add(o);
		return;
	}

	T old;
	T temp = o;

	for (size_t i = index; i < _items; i++)
	{
		old = _field[i];
		_field[i] = temp;
		temp = old;
	}
	_items++;
}

template <typename T, int startSize, int increase>
void IncreasingContainer<T, startSize, increase>::remove(int index)
{
	if (index > _items - 1) std::invalid_argument("Error - remove");
	else if (index == _items - 1) _items--;
	else
	{		
		for (size_t i = index; i < _items; i++)	_field[i] = _field[i + 1];		
		_items--;
	}
}
#endif
