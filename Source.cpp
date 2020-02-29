#include <iostream>
#include "LinkedList.h"


int main() {
	LinkedList floatlist = LinkedList(INT);
	char file[12] = "fileout.bin";
	int var1 = 4;
	int var2 = 6;
	int var3 = 4;
	int var4 = 3;
	int var5 = 69;
	int var6 = 1;
	int var7 = -1;
	floatlist.insertNode(APPEND, &var1);
	floatlist.display();
	floatlist.insertNode(APPEND, &var2);
	floatlist.display();
	floatlist.insertNode(APPEND, &var3);
	floatlist.display();
	floatlist.insertNode(APPEND, &var4);
	floatlist.display();
	floatlist.insertNode(APPEND, &var5);
	floatlist.display();
	floatlist.insertNode(APPEND, &var6);
	floatlist.display();
	floatlist.insertNode(APPEND, &var7);
	floatlist.display();
	floatlist.orderList();
	floatlist.display();
	floatlist.~LinkedList();
	return 0;
}