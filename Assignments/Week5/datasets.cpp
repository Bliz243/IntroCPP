// This is a unique solution for all 3 exercises: see main() below

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Each dataset is a vector of ints.
// This solutions uses an STL map to associate an identifier (a string)
// to each dataset.  This is not needed for solving the main exercises,
// but it is a flexible approach that addresses the optional challenge
typedef map< string , vector<int> > DataSet;

// Some function prototypes follow (their implementations are after main())

// A function that reads all datasets from the input
void read_datasets(DataSet & data);

// Exercise 1
void process1(DataSet & data);

// Exercise 2
void process2(DataSet & data);

// Exercise 3
void process3(DataSet & data);

int main() {
    DataSet my_datasets;

    read_datasets(my_datasets);

    process1(my_datasets); // Solves exercise 1
    // process2(my_datasets); // Solves exercise 2
    // process3(my_datasets); // Solves exercise 3

    return 0;
}

void read_datasets(DataSet & data) {
    string datasetId;
    double value;
    
    while(true) {
        // Read dataset identifier
        cin >> datasetId;

        // Abort if nothing more to read or unexpected input
        if (cin.fail()) {
            break;
        }

        // Add a new dataset if one named 'datasetId' does not exist
        if (data.find(datasetId) == data.end()) {
            data.insert(pair<string,vector<int>>(datasetId, vector<int>()));
        }

        // Read value
        cin >> value;
        data[datasetId].push_back(value);
    }
}

void process1(DataSet & data) {
    // Note that entries in map are iterated in order by their key.
    // In this case keys are strings, in lexicographical order.
    // For instance, "a" < "b"
    for (auto dataset : data) {
        sort(dataset.second.begin(), dataset.second.end());
        for (auto value : dataset.second) {
            cout << value << " " ;
        }
    }
}

void process2(DataSet & data) {
    int i = 0;
    bool some = true; // A boolean flag to remember if we found some element
    
    while (some) {
        some = false;
        for (auto dataset : data) {
            // Print the i-th element of dataset 'data' if it exists
            if (i < dataset.second.size()) {
                cout << dataset.second[i] << " " ;
                some = true;
            }
        }
        i = i + 1;
    }
}

void process3(DataSet & data) {
    int i = 0;
    bool some = true;
    double product_total = 0.0;
    double product_component = 1.0;
    
    while (some) {
        some = false;
        product_component = 1.0;
        for (auto dataset : data) {
            // Print the i-th element of dataset 'data' if it exists
            if (i < dataset.second.size()) {
                product_component *= dataset.second[i];
                some = true;
            } else {
                product_component = 0.0;
            }
        }
        product_total += product_component;
        i = i + 1;
    }

    cout << product_total ;
}

/* Some test cases
 
Exercise 1

a 3 b 2 b 1 a 1 a 4 b 2
1 3 4 1 2 2

a 3 a 2 a 3
2 3 3

b 6 b 5 b 4
4 5 6
 
 Exercise 2
 
 a 3 b 2 b 1 a 1 a 4 b 2
 3 2 1 1 4 2
 
 a 3 a 2 b 1
 3 1 2
 
 b 6 b 5 a 8
 8 6 5
 
 Exercise 3
 
 a 3 b 2 b 1 a 1 a 4 b 2
 15
 
 a 3 a 2 b 2 a 5 b 3
 12
 
 b 0 b 1 b 3 a 4 a 7 a 4 b 6
 19

*/
