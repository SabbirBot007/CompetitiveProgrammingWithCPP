#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "before sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    } cout << endl;

    for(int i = 0; i < n; i++){
        bool swapped = false;
        for(int j = 0; j < n; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j  + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

    cout << "after sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    } cout << endl;

    return 0;
}