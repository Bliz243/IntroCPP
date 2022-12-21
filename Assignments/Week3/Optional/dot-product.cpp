#include <iostream>
using namespace std;

int main() {
    unsigned int n; // Will contain the vectors length
    cin >> n;

    // Allocate the two vectors
    double *u = new double[n];
    double *v = new double[n];

    // Read the first vector
    for (unsigned int i = 0; i < n; i++) {
        cin >> u[i];
    }

    // Read the second vector
    for (unsigned int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Compute the dot product
    double dotProduct = 0.0; // We use this variable to accumulate the result
    for (unsigned int i = 0; i < n; i++) {
        dotProduct = dotProduct + (u[i] * v[i]);
    }

    // Don't forget to dellocate the arrays when done
    delete[] u;
    delete[] v;

    cout << dotProduct << endl;

    return 0;
}
