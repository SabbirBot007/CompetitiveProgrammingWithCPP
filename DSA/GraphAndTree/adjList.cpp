#include <bits/stdc++.h>

using namespace std; 

void addEdgeDirected(vector <vector <int>> &adj, int u, int v){
    adj[u].push_back(v); 
}

void addEdgeUndirected(vector <vector <int>> &adj, int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

void showAdjList(vector <vector <int>> &adj, int v){
    for(int i = 0; i < v; i++){
        cout << i << ": "; 
        for(int x : adj[i]){
            cout << x << ' '; 
        }cout << endl; 
    }
}

int main(){
    bool directed; 
    cout << "Enter 1 for directed graph and 0 for undirected: "; 
    cin >> directed;
    
    int V; cout << "Enter number of vertex: "; cin >> V; 
    vector <vector <int>> adj(V); 

    int e; cout << "Enter number of edges: "; cin >> e; 
    cout << "Enter " << e << " edges." << endl;  
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v; 
        if(directed) addEdgeDirected(adj, u, v); 
        else addEdgeUndirected(adj, u, v); 
    }

    showAdjList(adj, V); 
}