#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    if(this->itemsInfo.find(name) != this->itemsInfo.end()) {
        this->itemsInfo[name].quantity += quantity;
        this->itemsInfo[name].notes = itemsInfo[name].notes + ";" + notes;
    }
    else {
        this->items.push_back(name);
        this->itemsInfo[name] = {quantity, notes};
    }
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity){
     if(itemsInfo.find(name) != itemsInfo.end()){
        if(itemsInfo.at(name).quantity < quantity){
            return false;
        }
        itemsInfo.at(name).quantity -= quantity;
            if(itemsInfo.at(name).quantity <= 0){
                for(int i = 0; i < items.size(); i++){
                    if(items.at(i) == name){
                        items.erase(items.begin() + i);
                        break;
                    }
                }
                itemsInfo.erase(name);
                return true;
        }
        return true;
    } else
        return false;

}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    if (itemsInfo.find(newName) != itemsInfo.end()) {
        return false;
    } else {
        items.push_back(newName);
        itemsInfo[newName] = itemsInfo[name];
        return true;
    }

}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}




   /*  if (this->itemsInfo.find(name) != this->itemsInfo.end()){
        if (this->itemsInfo.at(name).quantity < quantity) {
            return false;
        }
        this->itemsInfo.at(name).quantity -= quantity;
        if (this->itemsInfo.at(name).quantity <= 0){
           for(int i = 0; i < this->items.size(); i++) {
            if(this->items[i].compare(name) == 0) {
                this->items.erase(this->items.begin() + i);
                break;
            }
        }
            return true;
        }
        return true;

    } else
        return false;
 */