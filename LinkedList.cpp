#include "LinkedList.h"
/*
Default type of the linked list is bool
*/
LinkedList::LinkedList() : 
	m_head (nullptr),
	m_ordered(false)
{
}


LinkedList::LinkedList(void(*displayFunc)(void* v), int(*compareFunc)(void* v,void * x)) :
	m_head(nullptr),
	m_ordered(false),
	m_displayfunc(displayFunc),
	m_comparefunc(compareFunc)
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
		Node* new_node = new Node(data,m_displayfunc);
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
		Node* new_node = new Node(data,m_displayfunc);
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

void LinkedList::orderList() {
	Node* trailtrail{};
	Node* trail{};
	Node* travel{};
	bool found = true;
	m_ordered = false;
	while (!m_ordered) {
		trailtrail = nullptr;
		trail = m_head;
		travel = m_head->getNext();
		found = false;
		while (travel != nullptr) {
			if (m_comparefunc(trail->getData(), travel->getData())) {
				found = true;
				if (trail == m_head) {
					m_head = travel;
					trail->setNext(travel->getNext());
					m_head->setNext(trail);
				}
				else {
					trailtrail->setNext(travel);
					trail->setNext(travel->getNext());
					travel->setNext(trail);
				}
				trailtrail = travel;
				trail = travel;
				travel = trail->getNext();
			}
			else {
				trailtrail = trail;
				trail = travel;
				travel = travel->getNext();

			}
		}
		if (!found) {
			m_ordered = true;
		}
	}
}
void LinkedList::serializeInts(char filename[])
{
	ofstream fout(filename, ios::out, ios::binary);
	Node* travel;
	if (m_head == nullptr) {
		cout << "linked list is empty." << endl;
	}
	else {
		travel = m_head;
		//write type
		while(travel != nullptr) {
			int* p = (int*)(travel->getData());
			fout.write(reinterpret_cast<char*>(p), sizeof(int));
			travel = travel->getNext();
		}
	}
	fout.close();
}

void LinkedList::serializeStrs(char filename[])
{
}

void LinkedList::deserializeInts(char filename[])
{
	Node* travel;
	void* data = new int;
	ifstream fin(filename, ios::binary);
	travel = m_head;
	while (!fin.eof()) {
		fin.read(reinterpret_cast<char*>(data), sizeof(int));
		int* p = (int*)(data);
		int n = *p;
		if (n > -300000) {
			if (m_head == nullptr) {
				travel = new Node(data, m_displayfunc);
				m_head = travel;
			}
			else {
				travel->setNext(new Node(data, m_displayfunc));
				travel = travel->getNext();
			}
		}
		data = new int;
	}
	delete data;
	fin.close();
}

void LinkedList::deserializeStrs(char filename[])
{
}
