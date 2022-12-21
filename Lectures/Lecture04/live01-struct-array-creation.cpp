// Example showing how to use 'struct'ures
#include <iostream>
#include <string>

#define MAX_SIZE 3

using namespace std;

struct employee {
    string name;
    string surname;
    unsigned int salary;
};

//This function is wrong: you cannot return pointers to local variables
employee* createArrayWrong(){
    employee employees[MAX_SIZE];
    employees[0] = {"Bjarne", "Stroustrup", 100000};
	employees[1] = {"John", "Doe", 50000};
    
    employees[2].name = "Margaret";
    employees[2].surname = "Hamilton";
    employees[2].salary = 500000;

    return employees;
}

//This function is right, as the array is instantiated on the heap
employee* createArray(){
    employee *employees = new employee[MAX_SIZE];
    employees[0] = {"Bjarne", "Stroustrup", 100000};
	employees[1] = {"John", "Doe", 50000};
    
    employees[2].name = "Margaret";
    employees[2].surname = "Hamilton";
    employees[2].salary = 500000;

    return employees;
}


void displayEmployee(employee e) {
    cout << "Name: " << e.name << "; surname: " << e.surname;
    cout << "; salary: " << e.salary << endl;
}

void raiseSalary(employee *e, int increment){
    e->salary = e->salary + increment;
}

int main() {
    
	//Calling this function would lead to undefined behavior
    //employee *employees = createArrayWrong();

    //This is the correct function
    employee *employees = createArray();

    string action; // Will contain the user-supplied command
    int increment;
    unsigned int n;

	while (true)
    {
        cin >> action;
        if (action == "raise")
        {
            cin >> n;
            cin >> increment;
            if (n < MAX_SIZE) {
                raiseSalary(&employees[n], increment);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "display")
        {
            cin >> n;
            if (n < MAX_SIZE) {
                displayEmployee(employees[n]);
            } else {
                cout << "Invalid employee number" << endl;
            }
        }
        else if (action == "quit")
        {
            //always free the heap
            delete[] employees;
            return 0;
        }
        else
        {
            cout << "ERROR: invalid command" << endl;
            return 1;
        }
    }

    return 0;
}
