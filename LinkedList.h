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
	~LinkedList();
	void insertNode(insertMode mode, void * data,dataType type);
	void deleteNode(void * datasearch);
	void display();
	void serialize(char filename[]);
	void deserialize(char filename[]);

private:
    Node* m_head;
};

