#include <iostream>
#include "LinkedList.h"

void makestr();
void makeint();
void deserializeint();
void deserializestr();
char file[12] = "fileout.bin";
void displayInt(void* i);
void displayStr(void* i);
int compareInt(void* v, void* x);
int compareStr(void* v, void* x);
LinkedList intlist = LinkedList(*displayInt,*compareInt);
LinkedList strlist = LinkedList(*displayStr, *compareStr);
int main() {
	deserializestr();
	intlist.~LinkedList();
	strlist.~LinkedList();
	return 0;
}
void makeint() {
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
	intlist.orderList();
	intlist.display();
	intlist.serializeInts(file);
}
void makestr() {
	char var1[] = "jacob";
	char var2[] = "tyler";
	char var3[] = "fortnite";
	char var4[] = "vegetable";
	char var5[] = "lol";
	char var6[] = "what";
	char var7[] = "cringe ass nae nae baby";
	strlist.insertNode(APPEND, &var1);
	strlist.display();
	strlist.insertNode(APPEND, &var2);
	strlist.display();
	strlist.insertNode(APPEND, &var3);
	strlist.display();
	strlist.insertNode(APPEND, &var4);
	strlist.display();
	strlist.insertNode(APPEND, &var5);
	strlist.display();
	strlist.insertNode(APPEND, &var6);
	strlist.display();
	strlist.insertNode(APPEND, &var7);
	strlist.display();
	strlist.orderList();
	strlist.display();
	strlist.serializeStrs(file);
}
void deserializeint() {
	intlist.deserializeInts(file);
	intlist.display();
}
void deserializestr() {
	strlist.deserializeStrs(file);
	strlist.display();
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
int compareInt(void* v, void* x)
{
	return (*(int*)v > * (int*)x);
}
int compareStr(void* v, void* x)
{
	return (_stricmp((char*)v, (char*)x))>0;
}
