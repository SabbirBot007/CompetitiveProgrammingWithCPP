#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int low, int high, int mid){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int subArr1[n1];
    int subArr2[n2];

    for(int i = 0; i < n1; i++){
        subArr1[i] = arr[low + i];
    }

    for(int i = 0; i <  n2; i++){
        subArr2[i] = arr[mid + i + 1];
    }

    int i = 0; int j = 0; int k = low;
    while(i < n1 && j < n2){
        (subArr1[i] <= subArr2[j]) ? arr[k++] = subArr1[i++] : arr[k++] = subArr2[j++]; 
        // arr[k++] = (subArr1[i] <= subArr2[j]) ? subArr1[i++] : subArr2[j++];
    }

    while(i < n1){
        arr[k++] = subArr1[i++];
    }

    while(j < n2){
        arr[k++] = subArr2[j++];
    }
}

void mergeSort(int arr[], int low, int high){

    if(low < high){
        int mid = low + (high - low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, high, mid);
    }
}

int main(){

    int  n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }cout << endl;

    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// void merge(int arr[], int strt, int end, int mid){

//     int n1 = mid - strt + 1;
//     int n2 = end - mid;
//     int subArr1[n1];
//     int subArr2[n2];

//     for(int i = 0; i < n1; i++){
//         subArr1[i] = arr[strt + i];
//     }

//     for(int i = 0; i < n2; i++){
//         subArr2[i] = arr[mid + i + 1];
//     }

//     int i = 0;
//     int j = 0; 
//     int k = strt;

//     while(i < n1 && j < n2){
//         if(subArr1[i] <= subArr2[j]){
//             arr[k] = subArr1[i];
//             i++;
//             k++;
//         }else{
//             arr[k] = subArr2[j];
//             j++;
//             k++;
//         }
//     }

//     while(i < n1){
//         arr[k] = subArr1[i];
//         i++;
//         k++;
//     }

//     while(j < n2){
//         arr[k] = subArr2[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int arr[], int strt, int end){ 
//     if(strt < end){
//         int mid = strt + (end - strt)/2;

//         mergeSort(arr, strt, mid);
//         mergeSort(arr, mid + 1, end);

//         merge(arr, strt,  end, mid);
//     }
// }

// int main() {

//     cout << "Enter the size of the array: ";
//     int n; cin >> n;
//     int arr[n];

//     cout << "Enter " << n << " elements: ";
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     cout << "Before sort: ";
//     for(int i = 0; i < n; i++){
//         cout <<  arr[i] << ' ';
//     }cout << endl;

//     mergeSort(arr, 0, n  - 1);

//     cout << "After sort: ";
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << ' ';
//     }cout << endl;

//     return 0;
// }