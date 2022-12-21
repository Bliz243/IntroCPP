#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    Elem *newList = nullptr;
    while (list != nullptr) {
        Elem *newElem = new Elem;
        newElem->value = list->value;
        newElem->times = list->times;
        newElem->next = newList;
        newList = newElem;
        list = list->next;
    }
    return newList;


}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    if(list1 == nullptr){
        return list2;
    }
    if(list2 == nullptr){
        return list1;
    }
    Elem *last = list1;
    while(last->next != nullptr){
        last = last->next;
    }
    if(last->value == list2->value){
        last->times += list2->times;
        last->next = list2->next;
    } else {
        last->next = list2;
    }
    return list1;

}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    int sum = 0;
    while(list != nullptr){
        sum += list->value * list->times;
        list = list->next;
    }
    return sum;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
