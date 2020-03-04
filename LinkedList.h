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
	LinkedList(void(*displayFunc)(void* v));
	~LinkedList();
	void insertNode(insertMode mode, void* data);
	void deleteNode(void * datasearch);
	void display();
	void orderList();
	void serializeInts(char filename[]);
	void serializeStrs(char filename[]);
	void deserializeInts(char filename[]);
	void deserializeStrs(char filename[]);

private:
	int compareInt(const void* arg1, const void* arg2);
	int compareCharStr(const void* arg1, const void* arg2);
	bool m_ordered;
	void (*m_displayfunc)(void* v);
    Node* m_head;
};

