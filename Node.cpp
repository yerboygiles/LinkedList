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
Node::Node(void* data, void(*displayFunc)(void*v)) :
	m_data(data),
	m_next(nullptr),
	m_DisplayFunc(displayFunc)
{}

void Node::setData(void * data)
{
	m_data = data;
}

void Node::setNext(Node * next)
{
	m_next = next;
}

void * Node::getData() 
{
	return m_data;
}

Node * Node::getNext() 
{
	return m_next;
}

void Node::display()
{
	m_DisplayFunc(m_data);
}
char* Node::toString()
{
	return (static_cast<char*>(m_data));
}