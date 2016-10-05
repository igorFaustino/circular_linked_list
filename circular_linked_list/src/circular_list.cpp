#include "circular_list.h"

Element* element_create(int id, string info)
{
   Element* e = new Element;
   e->id = id;
   e->info = info;
   e->next = NULL;

   return e;
}

void element_print(Element* e)
{
    cout << "{ " << e->id << ", " << e->info << " }" << endl;
}

void element_destroy(Element* e)
{
    if (e){
        delete e;
    }
}

List* list_create()
{
    List* list = new List;
    list->size = 0;
    list->cursor = NULL;

    return list;
}

void list_destroy(List* list)
{
    Element* p = list->cursor;
    Element* prev = NULL;
    if (list->cursor  && list->cursor->next != list->cursor){
        p = p->next;
        do{
            prev = p;
            p = p->next;
            element_destroy(prev);
        }while(p != list->cursor);
        element_destroy(p);
    } else if (list->cursor && list->cursor == list->cursor->next){
        element_destroy(p);
    }
    delete list;
}

void list_insert(List* list, Element* e)
{
    if (!list->cursor){
        list->cursor = e;
        e->next = list->cursor;
    } else {
        e->next = list->cursor->next;
        list->cursor->next = e;
    }
    list->size++;
}

int list_remove(List* list)
{
    if(!list->cursor){
        return -1;
    }
    Element* p = list->cursor;
    Element* second = p->next;
    if (p != second){
        p->next = second->next;
    } else {
        list->cursor = NULL;
    }
    element_destroy(second);
    list->size--;
    return 0;
}

void list_print(List* list)
{
    Element* p = list->cursor;
    cout << "Circular Linked List\nSize: " << list->size << "\n[" << endl;
    if(list->cursor){
        do {
            element_print(p);
            p = p->next;
        } while (p != list->cursor);
    }
    cout << "]\n" << endl;
}

void list_cursorNext(List* list)
{
    if (list->cursor){
        list->cursor = list->cursor->next;
    }
}

void list_cursorAdvance(List* list, int pos)
{
    for (int i = 0; i < pos; i++){
        list_cursorNext(list);
    }
}
