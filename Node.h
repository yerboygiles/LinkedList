#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum dataType { BOOL, CHAR, INT, FLOAT, STRING, VOID };

class Node
{
public:
	Node();
	Node(void * data);
	~Node();
	void setData(void * data);
	void setNext(Node* next);
	void * getData();
	Node * getNext();
	void display(dataType type);
private:
	Node * m_next;
	void * m_data;
};