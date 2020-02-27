#include "LinkedList.h"
/*
Default type of the linked list is bool
*/
LinkedList::LinkedList() : 
	m_head (nullptr),
	m_ordered(false), 
	m_type(BOOL)
{

}
LinkedList::LinkedList(dataType type) :
	m_head(nullptr),
	m_ordered(false),
	m_type(BOOL)
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

void LinkedList::insertNode(insertMode mode, void* data)
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
		travel->display(m_type);
		for (int i = 0; travel->getNext() != nullptr; i++) {
			travel = travel->getNext();
			cout << "list segment: " << i << ", ";
			travel->display(m_type);
		}
	}
	cout << endl;
}
void LinkedList::orderList() {
	Node* travel;
	Node* trail;
	Node* back;
	Node* front;
	bool changed = false;
	while (!m_ordered) {
		if (m_head==nullptr || m_head->getNext() == nullptr) {
			m_ordered = true;
			break;
		}
		else {
			trail = m_head;
			travel = m_head->getNext();
			while (travel->getNext() != nullptr) {
				trail = travel;
				travel = travel->getNext();

			}
		}
	}
}
/*
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
			switch (travel->getType()) {
			case BOOL:
				fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(bool));
				break;
			case CHAR:
				fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(char));
				break;
			case INT:
				fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(int));
				break;
			case FLOAT:
				fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(float));
				break;
			case STRING:
				fout.write(reinterpret_cast<char*>(travel->getType()), sizeof(string));
				break;
			}
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
		fin.read(reinterpret_cast<char*>(&type), sizeof(type));
		fin.read(reinterpret_cast<char*>(&data), sizeof(data));
		new_node = new Node(data, type);
		travel = m_head;
		while (travel->getNext() != nullptr) {
			travel = travel->getNext();
		}
		travel->setNext(new_node);
	}
	fin.close();
}
*/