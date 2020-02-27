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
	case BOOL:
		cout << std::boolalpha << *static_cast<bool*>(m_data) << endl;
		break;
	case CHAR:
		cout << *static_cast<char*>(m_data) << endl;
		break;
	case INT:
		cout << *static_cast<int*>(m_data) << endl;
		break;
	case FLOAT:
		cout << *static_cast<float*>(m_data) << endl;
		break;
	case STRING:
		cout << *static_cast<string*>(m_data) << endl;
		break;
	}
}
void Node::display(dataType type)
{
	switch (type) {
	case BOOL:
		cout << std::boolalpha <<*static_cast<bool*>(m_data) << endl;
		break;
	case CHAR:
		cout << *static_cast<char*>(m_data) << endl;
		break;
	case INT:
		cout << *static_cast<int*>(m_data) << endl;
		break;
	case FLOAT:
		cout << *static_cast<float*>(m_data) << endl;
		break;
	case STRING:
		cout << *static_cast<string*>(m_data) << endl;
		break;
	}
}