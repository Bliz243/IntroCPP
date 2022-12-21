// This is a unique solution for both "Fun with bags 1" and "Fun with bags 2".
// To change the bag behaviour (set or multiset) read the comments in main()

#include <iostream>

using namespace std;

void add(unsigned int bag[], bool multiset, unsigned int x) {
    bag[x] = multiset ? (bag[x] + 1) : 1;
}

void del(unsigned int bag[], unsigned int x) {
    if (bag[x] > 0) {
        bag[x] = bag[x] - 1;
    }
}

void query(unsigned int bag[], unsigned int x) {
    if (bag[x] > 0) {
        cout << "T" ;
    } else {
        cout << "F" ;
    }
}

// Maximum value stored in the bag
#define MAX_VALUE 1000

int main(void) {
    string action;  // Will contain the user-supplied command
    unsigned int x; // Will contain the user-supplied value
    unsigned int bag[MAX_VALUE+1]; // The bag for values 0..1000 (included)

    // Set this variable to 'false' to implement a set, and 'true' for multiset
    bool multiset = true;

    while (true) {
        cin >> action ;
        if (action == "add") {
            cin >> x;
            add(bag, multiset, x);
        } else if (action == "del") {
            cin >> x;
            del(bag, x);
        } else if (action == "qry") {
            cin >> x;
            query(bag, x);
        } else if (action == "quit") {
            return 0;
        } else {
            cout << "ERROR: invalid command" << endl;
            return 1;
        }
    }
}
