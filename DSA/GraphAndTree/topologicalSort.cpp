#include <bits/stdc++.h>

using namespace std; 

void addEdge(vector <vector <int>> &adj, int u, int v){
    adj[u].push_back(v); 
}

void topologicalSortUtil(vector <vector <int>> &adj, vector <bool> &visited, stack <int> &st, int s){
    visited[s] = true; 
    for(int i : adj[s]){
        if(!visited[i]){
            topologicalSortUtil(adj, visited, st, i); 
        }
    }

    st.push(s); 
}

vector <int> topologicalSort(vector <vector <int>> &adj, int V){
    vector <bool> visited(V, false); 
    vector <int> res;
    stack <int> st; 
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            topologicalSortUtil(adj, visited, st, i); 
        }
    }

    while(!st.empty()){
        res.push_back(st.top()); 
        st.pop(); 
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

    vector <int> res = topologicalSort(adj, V); 

    for(int i : res){
        cout << i << ' '; 
    } cout << endl; 
}