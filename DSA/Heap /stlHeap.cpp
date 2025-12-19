#include <bits/stdc++.h>

using namespace std; 

int main(){

    vector <int> v = {20, 30, 35, 36, 40, 50}; 

    make_heap(v.begin(), v.end());  // converting vector into heap 

    cout << "The heap elements are: "; 
    for(int x : v) cout << x << ' '; 
    cout << endl; 

    // sort_heap(v.begin(), v.end());   // sorting heap 

    // cout << "Heap elements after sorting: "; 

    // for(int x : v) cout << x << ' '; 
    // cout << endl; 

    v.push_back(100); 
    cout << "Heap after push_back(): "; 

    for(int x : v) cout << x << ' '; 
    cout << endl; 

    push_heap(v.begin(), v.end()); // take the pushed back element in the right place 
    cout << "Heap after push_heap(): "; 

    for(int x : v) cout << x << ' '; 
    cout << endl; 

    pop_heap(v.begin(), v.end()); // move the largest or top element to the end
    cout << "Heap after pop_heap(): "; 

    for(int x : v) cout << x << ' '; 
    cout << endl; 

    v.pop_back(); 
    cout << "Heap after pop_back(): "; 

    for(int x : v) cout << x << ' '; 
    cout << endl; 

    vector <int> v1 = {9, 3, 5, 11, 4}; 

    bool heap = is_heap(v1.begin(), v1.end()); // check if v(vector) is max heap or not  
    cout << "v1 is_heap(): " << heap << endl; 
    
    cout << "v is_heap(): " << is_heap(v.begin(), v.end()) << endl; 

    auto it = is_heap_until(v1.begin(), v1.end()); // store the position where the container violates the rule of a heap 
    cout << "The heap elements is v1: "; 
    for(auto i = v1.begin(); i != it; i++){
        cout << *i << ' '; 
    } cout << endl; 

    return 0; 
}