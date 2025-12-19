#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int length = (max - min) + 1;
    int freqArray[length] = {0};
    for(int i = 0; i < n; i++){
        freqArray[arr[i] - min]++;
    }

    int sortedArray[n];
    int k = 0; 
    for(int i = 0; i < length; i++){
        for(int j = 0; j < freqArray[i]; j++){
            sortedArray[k++] = i + min;
        }
    }

    for(int i = 0; i < n; i++){
        cout << sortedArray[i] << ' ';
    }cout << endl;

    return 0;
}