#include <iostream>
#include "LinkedList.h"


int main() {
	LinkedList list = LinkedList();
	char file[12] = "fileout.bin";
	string var1 = "fortnite";
	float var2 = 4.5f;
	int var3 = 69;
	char var4 = 'F';
	bool var5 = false;
	list.insertNode(PREPEND, &var1, STRING);
	list.display();
	list.insertNode(APPEND, &var2, FLOAT);
	list.display();
	list.insertNode(PREPEND, &var3, INT);
	list.display();
	list.insertNode(APPEND, &var4, CHAR);
	list.display();
	list.insertNode(PREPEND, &var5, BOOL);
	list.display();
	list.deleteNode(&var2);
	list.display();
	list.serialize(file);
	list.~LinkedList();
	return 0;
}