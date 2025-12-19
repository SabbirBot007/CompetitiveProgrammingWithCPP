#include <bits/stdc++.h>

using namespace std; 

const int N = INT_MAX;  
int parent[N];
int Size[N]; 

void make(int v){
    parent[v] = v; 
    Size[v] = 1; 
}

int find(int v){
    if(v == parent[v]) 
        return v; 
    else 
        return parent[v] = find(parent[v]); // used path compression 
        // nive implementation 
        // return find(parent[v]); 
}

void Union(int a, int b){
    a = find(a); 
    b = find(b); 

    // used union by size 
    if(a != b){
        if(Size[a] < Size[b]) swap(a, b); 
        parent[b] = a; 
        Size[a] += b; 
    }

    // nive implementation 
    // void union_sets(int a, int b) {
    // a = find_set(a);
    // b = find_set(b);
    // if (a != b)
    //     parent[b] = a;
    // }
}

int main(){

    int n, k; 
    cin >> n >> k; 

    for(int i = 1; i <= n; i++){
        make(i); 
    }

    while(k--){
        int u, v; cin >> u >> v; 
        Union(u, v); 
    }

    // finding connected components 
    int connected_comp = 0; 
    for(int i = 1; i <= n; i++){
        if(parent[i] == i) connected_comp++; 
    }

    return 0; 
}