#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    int temp  = a; 
    a = b; b = temp; 
}

class MinHeap {
    int * harr;  // pointer ro array of element in heap 
    int capacity;  // max possible size of the heap 
    int heapSize;  // current size of the heap 

    public: 

    MinHeap(int cap){
        heapSize = 0; 
        capacity = cap; 
        harr = new int[cap]; 
    }

    int parent(int i){ return (i - 1)/2; }

    int left(int i){ return (2*i) + 1; }

    int right(int i){ return (2*i) + 2; }

    void heapify(int i){
        int l = left(i); 
        int r = right(i); 
        int smallest = i; 

        if(l < heapSize && harr[l] < harr[i]) smallest = l; 
        if(r < heapSize && harr[r] < harr[smallest]) smallest = r; 

        if(smallest != i){
            swap(harr[i], harr[smallest]); 
            heapify(smallest); 
        }
    }

    int extractMin(){
        if(heapSize <= 0) return INT_MAX; 
        if(heapSize == 1){
            heapSize--; 
            return harr[0]; 
        }

        int root = harr[0]; 

        harr[0] = harr[heapSize - 1]; 
        heapSize--; 
        heapify(0); 

        return root; 
    }

    void decreaseKey(int i, int val){
        harr[i] = val; 

        while(i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i], harr[parent(i)]); 
            i = parent(i); 
        }
    }

    int getMin(){ return harr[0]; }

    void deleteKey(int i){
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    }

    void insertKey(int val){
        if(heapSize == capacity){
            cout << "Overflow: Can't insert key." << endl; 
            return; 
        }

        heapSize++; 
        int i = heapSize - 1; 
        harr[i] = val; 

        while(i != 0 && harr[i] < harr[parent(i)]){
            swap(harr[i], harr[parent(i)]); 
            i = parent(i); 
        }
    }
}; 

int main(){

    MinHeap h(20); 
    h.insertKey(5); 
    h.insertKey(10); 
    h.deleteKey(1); 
    h.insertKey(200); 
    h.insertKey(12); 
    h.insertKey(100); 

    cout << h.extractMin() << ' '; 
    cout << h.getMin() << ' '; 

    h.decreaseKey(2, 2);
    cout << h.getMin();  
    
    return 0; 
}