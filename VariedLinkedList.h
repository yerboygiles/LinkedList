#pragma once
#include "Linkedlist.h"
class VariedLinkedList
{
public:
	VariedLinkedList();
	VariedLinkedList(dataType type);
	~VariedLinkedList();
	void insertNode(insertMode mode, void* data);
	void deleteNode(void* datasearch);
	void display();
	void orderList();
	/*
	void serialize(char filename[]);
	void deserialize(char filename[]);
	*/
private:
	bool m_ordered;
	Node* m_head;
};

