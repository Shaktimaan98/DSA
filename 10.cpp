#include <iostream>
using namespace std;

class hp {
    int heap[20], heap1[20], n1, i;

public:
    hp() {
        heap[0] = 0;  // Heap size indicator
        heap1[0] = 0; // Heap size indicator
    }

    void getdata();
    void insertMaxHeap(int heap[], int);
    void upAdjustMax(int heap[], int);
    void insertMinHeap(int heap1[], int);
    void upAdjustMin(int heap1[], int);
    void minmax();
};

// Function to input student marks
void hp::getdata() {
    cout << "\nEnter the number of students: ";
    cin >> n1;

    cout << "\nEnter the marks: ";
    for (i = 0; i < n1; i++) {
        int x;
        cin >> x;
        insertMaxHeap(heap, x);  // Insert into max heap
        insertMinHeap(heap1, x); // Insert into min heap
    }
}

// Insert into Max Heap
void hp::insertMaxHeap(int heap[], int x) {
    int n = heap[0]; // Get current size
    heap[n + 1] = x;
    heap[0] = n + 1; // Update heap size
    upAdjustMax(heap, n + 1);
}

// Heapify upwards (Max Heap)
void hp::upAdjustMax(int heap[], int i) {
    while (i > 1 && heap[i] > heap[i / 2]) { // Compare with parent
        swap(heap[i], heap[i / 2]); // Swap if greater
        i = i / 2;
    }
}

// Insert into Min Heap
void hp::insertMinHeap(int heap1[], int x) {
    int n = heap1[0];
    heap1[n + 1] = x;
    heap1[0] = n + 1;
    upAdjustMin(heap1, n + 1);
}

// Heapify upwards (Min Heap)
void hp::upAdjustMin(int heap1[], int i) {
    while (i > 1 && heap1[i] < heap1[i / 2]) { // Compare with parent
        swap(heap1[i], heap1[i / 2]); // Swap if smaller
        i = i / 2;
    }
}

// Display min and max marks
void hp::minmax() {
    cout << "\nMax Marks: " << heap[1]; // Root of max heap
    cout << "\nHeap Structure (Max Heap): ";
    for (i = 1; i <= heap[0]; i++) {
        cout << heap[i] << " ";
    }

    cout << "\n\nMin Marks: " << heap1[1]; // Root of min heap
    cout << "\nHeap Structure (Min Heap): ";
    for (i = 1; i <= heap1[0]; i++) {
        cout << heap1[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    hp h;
    h.getdata();
    h.minmax();
    return 0;
}
