#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* BuildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);

    return root;
}

//Pre-order
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<< root->data <<endl;
    preOrder(root->left);
    preOrder(root->right);
}

//In-order
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    
    inOrder(root->left);
    cout<<root->data <<endl;
    inOrder(root->right);
}

//Post-Order
void PostOrder(Node* root){
    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data <<endl;
}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5};
    Node* root = BuildTree(preorder);
    preOrder(root);
}

//Travel Traversing
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<< curr->data <<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout<< endl;
}

//Travel Traversing(print the element one by one)
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<< curr->data <<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout<< endl;
}