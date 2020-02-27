#include <iostream>
#include "LinkedList.h"


int main() {
	LinkedList floatlist = LinkedList();
	char file[12] = "fileout.bin";
	string var1 = "this is a string";
	float var2 = 4.5f;
	int var3 = 69;
	char var4 = 'F';
	bool var5 = false;
	floatlist.insertNode(APPEND, &var2);
	floatlist.display();
	floatlist.insertNode(PREPEND, &var3);
	floatlist.display();
	floatlist.insertNode(APPEND, &var4);
	floatlist.display();
	floatlist.~LinkedList();
	return 0;
}