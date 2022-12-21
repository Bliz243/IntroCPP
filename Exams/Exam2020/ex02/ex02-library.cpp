#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    // Write your code here
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    // Write your code here
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
