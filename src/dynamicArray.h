#ifndef DYNAMIC_ARRAY_
#define DYNAMIC_ARRAY_

#include <string>
#include <iostream>
#include <fstream>

template <class T>
class DynamicArray
{
private:
	T *data;
	int length; // current length
	int size; // array size
	bool memoryAllocation(int allocSize);
public:
	DynamicArray(int size);
	~DynamicArray();
	bool insert(T value);
	bool remove(int id);
	bool remove(std::string id);
	T* search(int id);
	T* search(std::string title);
	int getLength() {return length;}
	void print();
	void printSearch(int id);
	void printSearch(std::string id);
	void outputData(ofstream &stream);
	bool access(int pos, T &item);
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
void DynamicArray<T>::outputData(ofstream &stream)
{
	for (int i = 0; i < length; i++)
	{
		stream<<data[i]<<std::endl;
	}
}

template <class T>
void DynamicArray<T>::printSearch(int id)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == id)
			std::cout<<data[i]<<" "<<std::endl;
	}
}

template <class T>
void DynamicArray<T>::printSearch(string id)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == id)
			std::cout<<data[i]<<" "<<std::endl;
	}
}

template <class T>
bool DynamicArray<T>::access(int pos,T &item)
{
	if(pos >= 0 && pos < length)
	{
		item = data[pos];
		return true;
	}
	return false;
}

template <class T>
bool DynamicArray<T>::memoryAllocation(int allocSize)
{
	T *temp = new T[size+allocSize];
	if (temp)
	{
		for (int i = 0; i < length; i++)
		{
			temp[i] = this->data[i];
		}
		this->size += allocSize;
		return true;
	}
	return false;
}
#endif /* DYNAMIC_ARRAY_ */
