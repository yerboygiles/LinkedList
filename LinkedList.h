#pragma once
#include "Node.h"
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;

enum insertMode{APPEND,PREPEND};

class LinkedList
{
public:
	LinkedList(dataType type);
	~LinkedList();
	void insertNode(insertMode mode, void * data);
	void deleteNode(void * datasearch);
	void display();
	void orderList();
	/*
	void serialize(char filename[]);
	void deserialize(char filename[]);
	*/

private:
	bool m_ordered;
	dataType m_type;
    Node* m_head;
};

