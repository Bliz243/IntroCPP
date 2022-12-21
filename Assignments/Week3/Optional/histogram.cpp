#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    unsigned int k; // Interval size
    unsigned int n; // Data set size
    unsigned int m; // Maximum value in the data set
    unsigned int l; // Number of intervals

    // Read number of intervals
    cin >> l;
    // Read size of the data set
    cin >> n;

    // Create an array to store the data set
    unsigned int *values = new unsigned int[n];

    // Read the data set into the values array
    for (unsigned int i = 1; i <= n; i++) {
        cin >> values[i-1];
    }

    // Compute the maximum value to decide the size of the histogram.
    // Note: this could be done more efficiently while reading the data set...
    m = 0;
    for (unsigned int i = 1; i <= n; i++) {
        if (values[i-1] > m) {
            m = values[i-1];
        }
    }

    // Calculate the size of intervals
    k = ceil(m / (double)l);
    
    // Subtle case that arises if m = 0 yielding 0 size
    if (k == 0) {
        k = 1;
    }

    // Create an array to store the histogram
    unsigned int *histogram = new unsigned int[l];
    
    // Initialize histogram
    for (unsigned int i = 0; i < l; i++) {
        histogram[i] = 0;
    }

    // Compute histogram based on dataset
    for (unsigned int i = 0; i < n; i++) {
        // Here we ensure that the histogram index is within the array bounds.
        // This takes care of the "special case" described in the exercise
        unsigned int index = min(values[i]/k, l-1);
        histogram[index]++;
    }

    // Output the result
    for (unsigned int i = 0; i < l; i++) {
        cout << i*k << ": " << histogram[i] << endl;
    }

    // Remember to deallocate the arrays created with 'new'
    delete[] values;
    delete[] histogram;

    return 0;
}
