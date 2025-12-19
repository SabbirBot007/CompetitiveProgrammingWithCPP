#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    const int N = 1e8;
    vector <bool> v(N + 1, true);
    v[0] = v[1] = false;
 
    for(int i = 2; i*i <= N; i++){
        if(v[i]){
            for(int j = i*2; j <= N; j += i){
                v[j] = false; 
            }
        }
    }
 
    cout << 2 << endl;
    int count = 1;
 
    for(int i = 3; i <= N; i++){
        if(v[i]){
            count++;
            if(count%100 == 1){
                cout << i << endl;
            }
        }
        
    }
 
    return 0;
}