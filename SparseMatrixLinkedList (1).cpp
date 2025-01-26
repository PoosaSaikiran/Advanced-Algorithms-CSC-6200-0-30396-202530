
#include <iostream>
using namespace std;

// Node structure for representing a non-zero element
struct Node {
    int row, col, value; // Row index, Column index, and Value of the non-zero element
    Node* next;          // Pointer to the next node

    // Constructor to initialize a node
    Node(int r, int c, int val) : row(r), col(c), value(val), next(nullptr) {}
};

// Sparse Matrix implementation using Linked List
class SparseMatrixLinkedList {
private:
    Node* head; // Head of the linked list

public:
    // Constructor to initialize the linked list
    SparseMatrixLinkedList() : head(nullptr) {}

    // Function to insert a non-zero element into the linked list
    void insert(int row, int col, int value) {
        Node* newNode = new Node(row, col, value); // Create a new node
        if (!head) {
            head = newNode; // If the list is empty, set the new node as the head
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newNode; // Append the new node at the end
        }
    }

    // Function to display the sparse matrix in (row, column, value) format
    void display() const {
        if (!head) {
            cout << "Sparse Matrix is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Row\tCol\tValue" << endl;
        while (temp) {
            cout << temp->row << "\t" << temp->col << "\t" << temp->value << endl;
            temp = temp->next;
        }
    }

    // Destructor to free memory and delete the linked list
    ~SparseMatrixLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix (row by row):" << endl;
    SparseMatrixLinkedList sml;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            cin >> value;
            if (value != 0) { // Check for non-zero value before calling insert()
                sml.insert(i, j, value);
            }
        }
    }

    // Display the linked list representation of the sparse matrix
    cout << "Sparse Matrix Representation using Linked List:" << endl;
    sml.display();

    return 0;
}
