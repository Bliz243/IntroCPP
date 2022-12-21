#include <iostream>
using namespace std;

int main() {
    unsigned int n; // Will contain the number of values
    cin >> n;

    // We can solve this exercise without using arrays (try it!)
    // Here we use arrays just to practice

    // Allocate an array that will hold the n integers.
    // Since the integers will be positive, we can use type unsigned int
    unsigned int *values = new unsigned int[n];

    // Read the n values
    for (unsigned int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Now let's check whether the values are sorted
    bool sorted = true;

    // We begin the loop with 1, so it does not run for n=0 and n=1.
    // This handles all possible lengths of the sequence
    for (unsigned int i = 1; i < n; i++) {
        if (values[i-1] > values[i]) {
            sorted = false;
            break; // The list is unsorted, no need to check more values
        }
    }

    delete[] values; // Don't forget to dellocate the array when done

    if (sorted) {
        cout << "SORTED" << endl;
    } else {
        cout << "UNSORTED" << endl;
    }

    return 0;
}