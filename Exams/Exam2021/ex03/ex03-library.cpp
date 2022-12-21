#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    for (int i = 0; i < roomNames.size(); i++) {
        if (roomNames[i] == name) {
            return;
        }
    }
    roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    bool roomExists = false;
    for (int i = 0; i < roomNames.size(); i++) {
        if (roomNames[i] == roomName) {
            roomExists = true;
            break;
        }
    }
    if (!roomExists) {
        return;
    }
    for (auto it = roomOccupancy.begin(); it != roomOccupancy.end(); it++) {
        if (it->second.id == guestId) {
            return;
        }
    }
    if (roomOccupancy.find(roomName) == roomOccupancy.end()) {
        roomOccupancy[roomName] = {guestName, guestId};
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    for (int i = 0; i < roomNames.size(); i++) {
        if (roomOccupancy.find(roomNames[i]) == roomOccupancy.end()) {
            continue;
        }
        Guest g = roomOccupancy[roomNames[i]];
        if (guestName == "*" && guestId == "*") {
            cout << roomNames[i] << endl;
        } else if (guestName == "*" && guestId == g.id) {
            cout << roomNames[i] << endl;
        } else if (guestName == g.name && guestId == "*") {
            cout << roomNames[i] << endl;
        } else if (guestName == g.name && guestId == g.id) {
            cout << roomNames[i] << endl;
        }
    }
    // Write your code here
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
