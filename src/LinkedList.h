#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>

template <class T>
class Node
{
public:
	T data;
	Node<T> *next;
};

template <class T>
class LinkedList
{
public:
	LinkedList() { head = 0;}
	virtual ~LinkedList();
	bool isEmpty(){ return head == 0; }
	int length();
	T* search(int id);
	T* search(std::string title);
	void insert(T data);
	void remove(int id);
private:
	Node<T>* remove(Node<T> *node, int id);
	T* search(Node<T> *node, int id);
	T* search(Node<T> *node, std::string title);
	Node<T> *head;
};

#endif /* LINKEDLIST_H_ */
