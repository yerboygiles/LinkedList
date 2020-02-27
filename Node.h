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
	void setType(dataType type);
	void * getData();
	Node * getNext();
	dataType getType();
	void display();
	void display(dataType type);
private:
	Node * m_next;
	void * m_data;
	dataType m_type;
};