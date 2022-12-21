#include <iostream>
using namespace std;

int main() {
    unsigned int n; // Will contain the number of values
    cin >> n;

    // Allocate an array that will hold the n integers.
    // Since the integers will be positive, we can use type unsigned int
    unsigned int *values = new unsigned int[n];

    // Read the n values
    unsigned int largest = 0; // Index of the largest number in the array
    for (unsigned int i = 0; i < n; i++) {
        cin >> values[i];
        if (values[i] > values[largest]) {
            largest = i;
        }
    }

    // Let's now print the array, highlighting the largest value
    for (unsigned int i = 0; i < n; i++) {
        if (i == largest) {
            cout << "*" << values[i] << "* ";
        } else {
            cout << values[i] << " ";
        }
    }
    cout << endl;

    delete[] values; // Don't forget to dellocate the array when done

    return 0;
}
