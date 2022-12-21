// A dynamically-allocated matrix
#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "How many rows and columns? ";
    cin >> rows;
    cin >> cols;

    // Allocate an array of pointers to 'double' values (one pointer per row)
    double **a = new double*[rows];
    for (int i = 0; i < rows; i++) {
        // Now each row pointer points to an array of 'double' values
        a[i] = new double[cols];
    }

    // Initialise the matrix with value 0 in each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = 0.0;
        }
    }

    // Display the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the matrix: delete each row, and then the array of pointers
    // We *cannot* begin by deleting the array of pointers!
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
