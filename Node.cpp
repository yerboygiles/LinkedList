#include "Node.h"

Node::Node()
{
	setData(0);
	setNext(nullptr);
}
Node::~Node()
{}
Node::Node(void * data) :
	m_data(data),
	m_next(nullptr)
{}
Node::Node(void* data, dataType type) :
	m_data(data),
	m_next(nullptr),
	m_type(type)
{}

void Node::setData(void * data)
{
	m_data = data;
}

void Node::setNext(Node * next)
{
	m_next = next;
}

void Node::setType(dataType type)
{
	m_type = type;
}

void * Node::getData() 
{
	return m_data;
}

Node * Node::getNext() 
{
	return m_next;
}

dataType Node::getType() 
{
	return m_type;
}

void Node::display()
{
	switch (m_type) {
	case CHARSTR:
		cout << *static_cast<char*>(m_data) << endl;
		break;
	case INT:
		cout << *static_cast<int*>(m_data) << endl;
		break;
	}
}
void Node::display(dataType type)
{
	switch (type) {
	case CHARSTR:
		cout << *static_cast<char*>(m_data) << endl;
		break;
	case INT:
		cout << *static_cast<int*>(m_data) << endl;
		break;
	}
}