#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if(list == nullptr){
        return 0;
    } else {
        return list->times + length(list->next);
    }
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    if(list == nullptr){
        list = new Elem;
        list->value = v;
        list->times = 1;
        list->next = nullptr;
        return list;
    }
    Elem *last = list;
    while(last->next != nullptr){
        last = last->next;
    }
    if(last->value == v){
        last->times = last->times + 1;
    } else {
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        last->next = e;
    }
    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    Elem *result = nullptr;
    for(unsigned int i = 0; i < n; i++){
        result = append(result, data[i]);
    }
    return result;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
