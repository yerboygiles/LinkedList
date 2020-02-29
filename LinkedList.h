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
	LinkedList();
	LinkedList(dataType type);
	~LinkedList();
	void insertNode(insertMode mode, void * data);
	void deleteNode(void * datasearch);
	void display();
	void orderList();
	void serialize(char filename[]);
	void deserialize(char filename[]);

private:
	int compareInt(const void* arg1, const void* arg2);
	int compareCharStr(const void* arg1, const void* arg2);
	bool m_ordered;
	dataType m_type;
    Node* m_head;
};

