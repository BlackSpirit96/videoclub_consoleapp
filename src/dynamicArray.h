#ifndef DYNAMIC_ARRAY_
#define DYNAMIC_ARRAY_

#include <string>
#include <iostream>
#include <fstream>


/*
 * A dynamic array class
 * used to store all the items
 * and customers lists on the program
 */

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

// DynamicArray(int size)
// set up array @size
template <class T>
DynamicArray<T>::DynamicArray(int size)
{
	this->data = new T[size];
	this->size = size;
	this->length = 0;
}

/*
 * ~DynamicArray()
 * deconstructor
 */
template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] data;
}

/*
 * insert(T value)
 * insert @value into table
 */
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

/*
 * remove(std::string id)
 * removes the item that meets
 * data[i] == id
 */
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

/*
 * remove(int id)
 * removes the item that meets
 * data[i] == id
 */
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

/*
 * search(int id)
 * search table for
 * data[i] == id
 */
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

/*
 * search(std::string id)
 * search table for
 * data[i] == id
 */
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

/*
 * print()
 * output table in std::cout
 */
template <class T>
void DynamicArray<T>::print()
{
	for (int i = 0; i < length; i++)
	{
		std::cout<<data[i]<<" "<<std::endl;
	}
}

/*
 * outputData(ofstream &stream)
 * output Table in stream
 */
template <class T>
void DynamicArray<T>::outputData(ofstream &stream)
{
	for (int i = 0; i < length; i++)
	{
		stream<<data[i]<<std::endl;
	}
}

/*
 *  printSearch(int id)
 *  search and output results
 */
template <class T>
void DynamicArray<T>::printSearch(int id)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == id)
			std::cout<<data[i]<<" "<<std::endl;
	}
}

/*
 *  printSearch(std::string id)
 *  search and output results
 */
template <class T>
void DynamicArray<T>::printSearch(string id)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == id)
			std::cout<<data[i]<<" "<<std::endl;
	}
}

/*
 * access(int pos,T &item)
 * return @item from @pos
 */
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

/*
 * memoryAllocation(int allocSize)
 * allocates @allocSize memory when needed
 */
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
