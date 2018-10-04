#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printContainer(const T &C) {
    for (auto x: C)
        cout << x << " ";
    cout << "\n";
}

void maxHeapify(vector<int> &A, int heapSize, int i) {
    auto left = 2*i + 1;
    auto right = 2*i + 2;
    auto max = i;

    if (left < heapSize && A[left] > A[max])
        max = left;

    if (right < heapSize && A[right] > A[max])
        max = right;

    if (max != i) {
        swap(A[i], A[max]);
        maxHeapify(A, heapSize, max);
    }
}

void buildHeap(vector<int> &A) {
    for (int i = A.size()/2; i > -1; --i) {
        maxHeapify(A, A.size(), i);
    }
}

void heapSort(vector<int> &A) {
    auto heapSize = A.size();
    buildHeap(A);
    for (int i = heapSize - 1; i > -1; --i) {
        swap(A[0], A[i]);
        printContainer(A);
        maxHeapify(A, --heapSize, 0);
    }
}


int main() {
    vector<int> A{7, 9, 8, 6, 5, 4, 3, 1, 2, 10};
    heapSort(A);
    printContainer(A);
    return 0;
}
