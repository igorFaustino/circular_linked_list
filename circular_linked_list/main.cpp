#include <iostream>
#include "circular_list.h"

using namespace std;

int main()
{
    List* list = list_create();
    list_insert(list, element_create(1, "Mickey"));
    list_insert(list, element_create(3, "Donald"));
    list_insert(list, element_create(2, "Goofy"));
    list_print(list);

    list_remove(list);
    list_print(list);
    list_remove(list);
    list_remove(list);
    list_remove(list);
    list_print(list);
    list_insert(list, element_create(1, "pink floyd"));
    list_insert(list, element_create(3, "def leppard"));
    list_insert(list, element_create(2, "deep purple"));
    list_print(list);
    list_cursorNext(list);
    list_print(list);
    list_cursorAdvance(list, 2);
    list_print(list);

    return 0;
}
