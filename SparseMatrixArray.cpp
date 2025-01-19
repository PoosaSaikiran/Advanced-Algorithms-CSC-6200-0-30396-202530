
#include <iostream>
using namespace std;

// Sparse Matrix Representation using Arrays
class SparseMatrixArray {
private:
    int rows[100], cols[100], values[100]; // Arrays to store row, column, and value
    int size;                             // Number of non-zero elements

public:
    SparseMatrixArray() : size(0) {}

    // Function to insert non-zero elements into the arrays
    void insert(int row, int col, int value) {
        if (value == 0) return;
        rows[size] = row;
        cols[size] = col;
        values[size] = value;
        size++;
    }

    // Function to display the arrays
    void display() const {
        if (size == 0) {
            cout << "Sparse Matrix is empty!" << endl;
            return;
        }
        cout << "Row\tCol\tValue" << endl;
        for (int i = 0; i < size; i++) {
            cout << rows[i] << "\t" << cols[i] << "\t" << values[i] << endl;
        }
    }
};

int main() {
    // Example sparse matrix
    int matrix[4][4] = {
        {0, 0, 3, 4},
        {0, 5, 7, 0},
        {0, 0, 0, 0},
        {0, 2, 6, 0}
    };

    // Using Arrays
    cout << "Sparse Matrix Representation using Arrays:" << endl;
    SparseMatrixArray sma;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sma.insert(i, j, matrix[i][j]);
        }
    }
    sma.display();

    return 0;
}
