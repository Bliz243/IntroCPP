#include <iostream>
#include "doubly-linked.h"

using namespace std;

// NOTE: Doubly linked lists can be implemented in different ways
// In this solution we have decided to have a circular list
// where the next element of the last one is the first one
// and the previous element of the first one is the last one
// This provides fast access to the last element in the list

List::List(void){
    // The constructor just needs to set first to nullptr
    first = nullptr;
}

// Recursive function to erase all elements in a linked list
void eraseR(Node *p){
    // If the list is empty, stop
    if (p == nullptr) return;
    // If the list has one element (next element is itself), we just delete it
    if (p->next == p) delete p;
    // Otherwise we delete the list recursively
    else {
        // Bypass the list node
        p->next->prev = p->prev;
        p->prev->next = p->next;
        // Delete the remaining list
        eraseR(p->next);
        // Delete the node
        delete p;
    }
}

List::~List(void){
    // The destructor needs to erase all dynamicall allocated nodes.
    // We can do it recursively
    eraseR(first);
    first = nullptr;
}

void List::insert(int n){
    Node * p;

    // Create new node
    p = new Node;
    p->val = n;

    // If the list is empty, then just update l to point to p
    if (first == nullptr){
        first = p;
        // Note that the next and prev links form a self-loop
        p->next = p;
        p->prev = p;
        return;
    }

    // If the list is not empty, we insert the new node at the end of the list
    Node * last;
    last = first->prev;
    first->prev = p;
    p->next = first;
    p->prev = last;
    last->next = p;

    return;
}

// We implement reverse recursively.
// The first argument is a reference to the pointer 'first' in the list class
// The second argument is pointing to the element to be reversed
void reverseR(Node *&first, Node *p){
    // If the list is empty, there is nothing to be done
    if (first == nullptr) return;

    // Reverse remaining list (if we are not at its end)
    if(p != first->prev){
        reverseR(first, p->next);
    }

    // Reverse links of current item
    Node *aux;
    aux = p->prev;
    p->prev = p->next;
    p->next = aux;

    // If this was the first item, set the new first to be the old last item
    if (p == first) {
        first = p->next;
    }

    return;
}

void List::reverse(void){
    // We invoke recursive implementation of reverse
    reverseR(first, first);
    return;
}

void printR(Node *&first, Node *p){
    // If the list is empty, there is nothing to be done
    if (first == nullptr) return;

    cout << p->val << " ";

    // Print the remaining list (if we are not at its end)
    if(p != first->prev){
        printR(first, p->next);
    } else{
        cout << endl;
    }

    return;
}

void List::print(){
    printR(first, first);
    return;
}
