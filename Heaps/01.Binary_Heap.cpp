#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr;     
    int capacity;  
    int heap_size; 

public:
    MinHeap(int capacity);
    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return (2 * i + 1); }
    int right(int i)  { return (2 * i + 2); }

    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { 
        cout << "[getMin] Returning root element: " << harr[0] << endl;
        return harr[0]; 
    }
    void deleteKey(int i);
    void insertKey(int k);
    
    // Helper function to visualize current array state
    void printHeapState() {
        cout << "Current Heap Array: [";
        for(int i = 0; i < heap_size; i++) {
            cout << harr[i] << (i == heap_size - 1 ? "" : ", ");
        }
        cout << "]" << endl << endl;
    }
};

MinHeap::MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
    cout << "[Constructor] Created MinHeap with capacity: " << cap << endl << endl;
}

void MinHeap::insertKey(int k){
    cout << "[insertKey] Attempting to insert: " << k << endl;
    if(heap_size == capacity){
        cout << "Overflow: Could not insertKey" << endl;
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    cout << " inserted at index " << i << ". Bubble up phase starting..." << endl;

    // FIX: Changed '=!' to '!='
    while (i != 0 && harr[parent(i)] > harr[i]){
        cout << "  Swapping index " << i << " (" << harr[i] << ") with parent index " << parent(i) << " (" << harr[parent(i)] << ")" << endl;
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    printHeapState();
}

void MinHeap::decreaseKey(int i, int new_val){
    cout << "[decreaseKey] Changing index " << i << " value from " << harr[i] << " to " << new_val << endl;
    harr[i] = new_val;
    cout << " Bubble up phase starting..." << endl;
    while (i != 0 && harr[parent(i)] > harr[i]){
        cout << "  Swapping index " << i << " (" << harr[i] << ") with parent index " << parent(i) << " (" << harr[parent(i)] << ")" << endl;
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    printHeapState();
}

int MinHeap::extractMin(){
    cout << "[extractMin] Requested." << endl;
    if(heap_size <= 0){
        cout << " Underflow: Heap empty." << endl;
        return INT_MAX;
    }

    if(heap_size == 1){
        heap_size--;
        cout << " Only 1 element left. Extracted: " << harr[0] << endl;
        printHeapState();
        return harr[0];
    }

    int root = harr[0];
    cout << " Root value to extract: " << root << ". Replacing root with last element: " << harr[heap_size - 1] << endl;
    harr[0] = harr[heap_size - 1];
    heap_size--;
    
    cout << " Running MinHeapify(0) to fix down-heap paths..." << endl;
    MinHeapify(0);
    
    cout << " Extracted min completed." << endl;
    printHeapState();
    return root;
}

void MinHeap::deleteKey(int i){
    cout << "[deleteKey] Deleting key at index: " << i << endl;
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    // FIX: Consistently compare left child against harr[smallest] instead of harr[i]
    if (l < heap_size && harr[l] < harr[smallest]){
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest]){
        smallest = r;
    }
    if (smallest != i){
        cout << "  [MinHeapify] Swapping element at index " << i << " (" << harr[i] << ") with index " << smallest << " (" << harr[smallest] << ")" << endl;
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    
    cout << "--- Execution results from main ---" << endl;
    int ext = h.extractMin();
    cout << ">> Main Output (extractMin): " << ext << endl << endl;
    
    int min1 = h.getMin();
    cout << ">> Main Output (getMin): " << min1 << endl << endl;
    
    h.decreaseKey(2, 1);
    
    int min2 = h.getMin();
    cout << ">> Main Output (getMin after decrease): " << min2 << endl << endl;

    return 0;
}
