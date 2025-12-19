#include <bits/stdc++.h>

using namespace std; 

void addEdge(vector <vector <int>> &adj, int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

void bfsmodule(vector <vector <int>> &adj, vector <bool> &visited, vector <int> &res, int s){
    queue <int> q; 

    visited[s] = true;
    q.push(s); 

    while(!q.empty()){
        int curr = q.front(); 
        q.pop(); 
        res.push_back(curr); 

        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true; 
                q.push(x); 
            }
        }
    }
}

vector <int> bfs(vector <vector <int>> &adj){
    int V = adj.size(); 
    vector <bool> visited(V, false); 
    vector <int> res; 
    

    // for connected graph ................... 
    // queue <int> q; 

    // int s = 0; 
    // visited[s] = true;
    // q.push(s); 

    // while(!q.empty()){
    //     int curr = q.front(); 
    //     q.pop(); 
    //     res.push_back(curr); 

    //     for(int x : adj[curr]){
    //         if(!visited[x]){
    //             visited[x] = true; 
    //             q.push(x); 
    //         }
    //     }
    // }



     

    // for disconnected graph 
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            bfsmodule(adj, visited, res, i); 
        }
    }

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

    vector <int> res = bfs(adj); 

    for(int i : res){
        cout << i << ' '; 
    } cout << endl;
}