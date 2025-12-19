#include <bits/stdc++.h>

using namespace std; 

void countingSort(int arr[], int n, int ex);
void radixSort(int arr[], int n, int max);

int main(){

    int n; cin >> n; 
    int max = 0; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
    }

    cout << "Before sort: " << ' ';
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }cout << endl; 

    radixSort(arr, n, max);

    cout << "After sort: " << ' ';
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }cout << endl; 

    return 0; 
}

void radixSort(int arr[], int n, int max){
    
    for(int i = 1; max/i > 0; i *=10){
        countingSort(arr, n, i);
    }
}

void countingSort(int arr[], int n, int ex){

    int temp[10] = {0};
    int output[n];

    for(int i = 0; i < n; i ++){
        temp[(arr[i]/ex)%10]++;
    }

    for(int i = 1; i < 10; i++){
        temp[i] += temp[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        output[temp[(arr[i]/ex)%10] - 1] = arr[i];
        temp[(arr[i]/ex)%10]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }

}
