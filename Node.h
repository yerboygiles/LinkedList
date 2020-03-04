#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum dataType {CHARSTR, INT, DEFAULT};


class Node
{
public:
	Node();
	Node(void * data);
	Node(void* data, void(*displayFunc)(void* v));
	~Node();
	void setData(void * data);
	void setNext(Node* next);
	void * getData();
	Node * getNext();
	void display();
	char* toString();
private:
	void (*m_DisplayFunc)(void* v);
	Node * m_next;
	void * m_data;
};