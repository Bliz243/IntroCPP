#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    for(Passenger *p = q; p != nullptr; p = p->next){
        if(p->ticket == ticket){
            return p;
        }
    }
    return nullptr;
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    if(q == nullptr){
        return q;
    }
    if(q->ticket == ticket){
        q = q->next;
        return q;
    }
    Passenger *p = q;
    p->next = remove(p->next, ticket);
    return p;
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    if(q == nullptr){
        return q;
    }
    if(q->priority != true){
        return priority(q->next);
    }
    Passenger *p = q;
    p->next = priority(p->next);
    return p;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
