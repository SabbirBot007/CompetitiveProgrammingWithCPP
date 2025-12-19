#include <bits/stdc++.h>

using namespace std; 

struct Node{
    int data; 
    Node * left; 
    Node * right; 

    Node(int val){
        data = val; 
        left = nullptr; 
        right = nullptr; 
    }
}; 

Node * buildTree(){
    int val; 
    cout << "Enter data(-1 for no node): "; 
    cin >> val; 

    if(val == -1){
        return nullptr; 
    }

    Node * temp = new Node(val); 

    cout << "Enter left child of " << val << endl; 
    temp -> left = buildTree(); 

    cout << "Enter rght child of " << val << endl; 
    temp -> right = buildTree(); 

    return temp; 
}

void traverse(Node * root){

    // inorder traversal 
    if(!root) return; 

    traverse(root -> left); 
    cout << root -> data << ' '; 
    traverse(root -> right); 





    // preorder traversal 
    // if(!root) return; 

    // cout << root -> data << ' '; 
    // traverse(root -> left); 
    // traverse(root -> right); 







    // postorder traversal 
    // if(!root) return; 

    // traverse(root -> left); 
    // traverse(root -> right); 
    // cout << root -> data << ' '; 
}

bool search(Node * root, int key){
    if(!root) return false; 

    if(root -> data == key) return true; 

    bool rightNode = search(root -> right, key); 
    if(rightNode) return true; 

    bool leftNode = search(root -> left, key); 

    return leftNode; 
}

void levelOrderTraverse(Node * root, int level, vector <vector <int>> & res){
    if(!root) return; 

    if(res.size() <= level) res.push_back({}); 

    res[level].push_back(root -> data); 

    levelOrderTraverse(root -> left, level + 1, res);
    levelOrderTraverse(root -> right, level + 1, res);  
}

Node * InsertNode(Node * root, int data){
    if(root == nullptr){
        root = new Node(data); 
        return root; 
    }

    queue <Node *> q; 
    q.push(root); 

    while(!q.empty()){
        Node * current = q.front();
        q.pop(); 
        
        if(current -> left != nullptr) q.push(current -> left); 
        else{
            current -> left = new Node(data);
            return root;  
        }

        if(current -> right != nullptr) q.push(current -> right); 
        else{
            current -> right = new Node(data); 
            return root; 
        } 
    }

    return root; 
}

Node * deletion(Node * root, int key){
    if(root == nullptr) return nullptr;


    if(root -> left == nullptr && root -> right == nullptr){
        if(root -> data == key) return nullptr; 
        else return root; 
    }

    queue <Node *> q; 
    q.push(root); 
    Node *current = nullptr; 
    Node * keyNode = nullptr; 

    while(!q.empty()){
        current = q.front(); 
        q.pop(); 

        if(current -> data == key) keyNode = current; 

        if(current -> left) q.push(current -> left); 

        if(current -> right) q.push(current -> right); 
    }

    if(keyNode != nullptr){
        keyNode -> data = current -> data; 
        q.push(root); 
        Node * dNode = current;
        
        while(!q.empty()){
            current = q.front(); 
            q.pop(); 

            if(current == dNode){
                current = nullptr; 
                delete(dNode); 
                break; 
            }

            if(current -> right){
                if(current -> right == dNode){
                    current -> right = nullptr; 
                    delete(dNode); 
                    break; 
                } q.push(current -> right);
            }

            if(current -> left){
                if(current -> left == dNode){
                    current -> left = nullptr; 
                    delete(dNode); 
                    break; 
                } q.push(current -> left); 
            }
        }
    }

    return root; 
}

int main(){

    Node * root = buildTree(); 

    // traversing 
    // cout << "Inorder traversal of tree: "; 
    // traverse(root); 
    // cout << endl; 




    // Searching 
    // int key; cin >> key; 
    // bool found = search(root, key); 

    // if(found) cout << key << " is available." << endl; 
    // else cout << key << " is not available." << endl; 




    // Level order traversing
    // vector <vector <int>> res; 
    // levelOrderTraverse(root, 0, res);  
    // for (vector <int> level : res){
    //     for(int val : level){
    //         cout << val << ' '; 
    //     } cout << endl; 
    // }





    // Insertion in binary tree 
    // int key;
    // cout << "Enter a value to insert: ";  cin >> key; 
    // root = InsertNode(root, key); 

    // traverse(root); 










    // deleting in binary tree
    int key; cin >> key; 
    deletion(root, key); 

    traverse(root); 

    return 0; 
}