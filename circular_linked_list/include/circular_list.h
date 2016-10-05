#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <string>

using namespace std;

struct Element {
	int id;
	string info;
	Element* next;
};

Element* element_create(int id, string info);
void element_print(Element* e);
void element_destroy(Element* e);

/////////////////////////////////////////////////

struct List {
	int size;
	Element* cursor;
};

List* list_create();
void list_destroy(List* list);
void list_insert(List* list, Element* e);
int list_remove(List* list);
void list_print(List* list);
void list_cursorNext(List* list);
void list_cursorAdvance(List* list, int pos);

#endif // CIRCULAR_LIST_H
