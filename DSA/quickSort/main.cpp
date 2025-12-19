#include <bits/stdc++.h>

using namespace std;

int partition2(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high){

    if(low < high){
        int pi = partition2(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n; 
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    quickSort(arr, 0, n - 1);

    cout << "After sort: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}