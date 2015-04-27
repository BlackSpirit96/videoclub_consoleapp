#include "LinkedList.h"

template <class T>
LinkedList<T>::~LinkedList()
{
	// TODO Auto-generated destructor stub
}

template <class T>
int LinkedList<T>::length()
{
	int count = 0;
	Node <T> *current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return count;
}

template <class T>
T* LinkedList<T>::search(int id)
{
	return search(head, id);
}

template <class T>
T* LinkedList<T>::search(std::string title)
{
	return search(head, title);
}
template <class T>
T* LinkedList<T>::search(Node<T> *node, int id)
{
	if(node == 0)
	{
		return 0;
	}
	else if (node->data == id)
	{
		return node->data;
	}
	else
	{
		return search(node->next, id);
	}
}

template <class T>
T* LinkedList<T>::search(Node<T> *node, std::string title)
{
	if(node == 0)
	{
		return 0;
	}
	else if (node->data == title)
	{
		return node->data;
	}
	else
	{
		return search(node->next, title);
	}
}

template <class T>
void LinkedList<T>::insert(T data)
{
	Node < T > *temp = new Node<T> ;
	temp->data = data;
	temp->next = head;
	head = temp;
}

template <class T>
void LinkedList<T>::remove(int id)
{
	remove(head, id);
}

template <class T>
Node<T>* LinkedList<T>::remove(Node<T> *node, int id)
{
	Node<T> *temp;
	if (node == 0)
	{
		temp = 0;
	}
	else if (node->data == id)
	{
		temp = node->next;
		delete node;
	}
	else if (node->data  != id)
	{
		temp = remove(node->next, id);
	}
	else
	{
		temp = node;
	}
	return temp;
}
