#ifndef DYNAMIC_ARRAY_
#define DYNAMIC_ARRAY_

#include <string>
#include <iostream>

template <class T>
class DynamicArray
{
private:
	T *data;
	int length;
	int size;
	bool memoryAllocation(int allocSize); // todo memoryAlloc
public:
	DynamicArray(int size);
	~DynamicArray();
	bool insert(T value);
	bool remove(int id);
	bool remove(std::string id);
	T* search(int id);
	T* search(std::string title);
	void print();
	void printSearch(std::string id); // todo void printSearch(std::string id)
};

template <class T>
DynamicArray<T>::DynamicArray(int size)
{
	this->data = new T[size];
	this->size = size;
	this->length = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] data;
}

template <class T>
bool DynamicArray<T>::insert(T value)
{
	bool flag = true;
	if (length == size)
	{
		flag = memoryAllocation(10);
	}

	if (flag)
	{
		data[length] = value;
		length++;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool DynamicArray<T>::remove(std::string id)
{
	bool flag = false;
	for(int i = 0; i < length; i++)
	{
		if (data[i] == id)
		{
			length--;
			flag = true;
		}
		if (flag)
		{
			data[i] = data[i+1];
		}
	}
	return flag;
}

template <class T>
bool DynamicArray<T>::remove(int id)
{
	bool flag = false;
	for(int i = 0; i < length; i++)
	{
		if (data[i] == id)
		{
			length--;
			flag = true;
		}
		if (flag)
		{
			data[i] = data[i+1];
		}
	}
	return flag;
}

template <class T>
T* DynamicArray<T>::search(int id)
{
	for(int i = 0; i < length; i++)
	{
		if (data[i] == id)
		{
			return &data[i];
		}
	}
	return 0;
}

template <class T>
T* DynamicArray<T>::search(std::string title)
{
	for(int i = 0; i < length; i++)
	{
		if (data[i] == title)
		{
			return &data[i];
		}
	}
	return 0;
}

template <class T>
void DynamicArray<T>::print()
{
	for (int i = 0; i < length; i++)
	{
		std::cout<<data[i]<<" "<<std::endl;
	}
}

template <class T>
bool DynamicArray<T>::memoryAllocation(int allocSize)
{
	return false;
}
#endif /* DYNAMIC_ARRAY_ */
