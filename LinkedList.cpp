#include "LinkedList.h"

LinkedList::LinkedList() : m_head (nullptr)
{

}

LinkedList::~LinkedList()
{
	Node* trail;
	while (m_head != nullptr) {
		trail = m_head;
		m_head = m_head->getNext();
		delete trail;
	}
}

void LinkedList::insertNode(insertMode mode, void* data, dataType type)
{
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

void LinkedList::deleteNode(void * datasearch)
{
	Node* trail;
	Node* travel;
	if (m_head == nullptr) {
		cout << "empty list" << endl;
	}
	else if(m_head->getData()==datasearch){
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

void LinkedList::display()
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

void LinkedList::serialize(char filename[])
{
	ofstream fout(filename, ios::out, ios::binary);
	Node* travel;
	if (m_head == nullptr) {
		cout << "linked list is empty." << endl;
	}
	else {
		travel = m_head;
		//write type
		for (int i = 0; travel != nullptr; i++) {
			fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(travel));
			fout.write(reinterpret_cast<char*>(travel->getData()), sizeof(travel->getData()));
			travel = travel->getNext();
		}
	}
	fout.close();

}

void LinkedList::deserialize(char filename[])
{
	Node* travel;
	Node* new_node;
	void* data;
	dataType type;
	ifstream fin(filename, ios::binary);
	travel = m_head;
	while (!fin.eof()) {
		fin.read(reinterpret_cast<char*>(type), sizeof(type));
		switch (type) {
		case BOOL:
			break;
		case CHAR:
			break;
		case INT:
			break;
		case FLOAT:
			break;
		case STRING:
			break;
		}
		fin.read(reinterpret_cast<char*>(data), sizeof(data));
		new_node = new Node();
		travel = m_head;
		while (travel->getNext() != nullptr) {
			travel = travel->getNext();
		}
		travel->setNext(new_node);
	}
	fin.close();
}
