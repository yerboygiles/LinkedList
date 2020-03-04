#include <iostream>
#include "LinkedList.h"

void serialize();
void deserialize();
char file[12] = "fileout.bin";
void displayInt(void* i);
void displayStr(void* i);
LinkedList intlist = LinkedList(*displayInt);
int main() {
	deserialize();
	intlist.~LinkedList();
	return 0;
}
void serialize() {
	int var1 = 4;
	int var2 = 6;
	int var3 = 4;
	int var4 = 3;
	int var5 = 69;
	int var6 = 1;
	int var7 = -1;
	intlist.insertNode(APPEND, &var1);
	intlist.display();
	intlist.insertNode(APPEND, &var2);
	intlist.display();
	intlist.insertNode(APPEND, &var3);
	intlist.display();
	intlist.insertNode(APPEND, &var4);
	intlist.display();
	intlist.insertNode(APPEND, &var5);
	intlist.display();
	intlist.insertNode(APPEND, &var6);
	intlist.display();
	intlist.insertNode(APPEND, &var7);
	intlist.display();
	intlist.serializeInts(file);
}
void deserialize() {
	intlist.deserializeInts(file);
	intlist.display();
}
void displayInt(void* i) {
	int* p = (int*)(i);
	int n = *p;
	cout << n << endl;
}
void displayStr(void* i) {
	char* p = (char*)(i);
	cout << p << endl;
}