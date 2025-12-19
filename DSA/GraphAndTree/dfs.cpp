#include <bits/stdc++.h>

using namespace std; 

void addEdge(vector <vector <int>> &adj, int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

void dfsmodule(vector <vector <int>> &adj, vector <bool> &visited, vector <int> &res, int s){
    visited[s] = true; 
    res.push_back(s); 

    for(int x : adj[s]){
        if(visited[x] == false){
            dfsmodule(adj, visited, res, x); 
        }
    }
}

vector <int> DFS(vector <vector <int>> &adj){
    vector <int> res; 
    vector <bool> visited(adj.size(), false); 

    // for disconnected graph
    for(int i = 0; i < adj.size(); i++){  
        if(visited[i] == false){
            dfsmodule(adj, visited, res, i); 
        }
    }

    // for connected graph
    // dfsmodule(adj, visited, res, 0);

    return res; 
}

int main(){

    int V; cout << "Enter number of vertex: "; cin >> V; 
    vector <vector <int>> adj(V); 

    int e; cout << "Enter number of edges: "; cin >> e; 
    cout << "Enter " << e << " edges." << endl;  
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v; 
        addEdge(adj, u, v); 
    }

    vector <int> res = DFS(adj); 
    for(int x : res){
        cout << x << ' '; 
    }cout << endl;
}