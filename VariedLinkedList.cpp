#include "VariedLinkedList.h"


VariedLinkedList::VariedLinkedList()
{
}

VariedLinkedList::VariedLinkedList(dataType type)
{
}

VariedLinkedList::~VariedLinkedList()
{
}

void VariedLinkedList::insertNode(insertMode mode, void* data)
{
	m_ordered = false;
	Node* travel;
	if (mode == APPEND) {
		Node* new_node = new Node(data);
		if (m_head == nullptr) {
			m_head = new_node;
		}
		else {
			travel = m_head;
			while (travel->getNext() != nullptr) {
				travel = travel->getNext();
			}
			travel->setNext(new_node);
		}
	}
	if (mode == PREPEND) {
		Node* new_node = new Node(data);
		if (m_head == nullptr) {
			m_head = new_node;
		}
		else {
			new_node->setNext(m_head);
			m_head = new_node;
		}
	}
}

void VariedLinkedList::deleteNode(void* datasearch)
{
	Node* trail;
	Node* travel;

	if (m_head == nullptr) {
		cout << "empty list" << endl;
	}
	else if (m_head->getData() == datasearch) {
		trail = m_head;
		m_head = m_head->getNext();
		delete trail;
	}
	else {
		travel = m_head;
		trail = m_head;
		while (travel != nullptr && travel->getData() != datasearch) {
			trail = travel;
			travel = travel->getNext();
		}
		if (travel == nullptr) {
			cout << "handle target not found error" << endl;
		}
		else {
			trail->setNext(travel->getNext());
			delete travel;
		}
	}
}

void VariedLinkedList::display()
{
	Node* travel;
	if (m_head == nullptr) {
		cout << "linked list is empty." << endl;
	}
	else {
		travel = m_head;
		cout << "head: ";
		travel->display();
		for (int i = 0; travel->getNext() != nullptr; i++) {
			travel = travel->getNext();
			cout << "list segment: " << i << ", ";
			travel->display();
		}
	}
	cout << endl;
}

void VariedLinkedList::orderList()
{
}
