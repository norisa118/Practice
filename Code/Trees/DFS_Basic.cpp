#include <stack>
#include <iostream>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

// helper function to create a node
Node* newNode(int data)
{
    // dynamically allocating memory
    Node* temp = new Node();
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

void DFS(Node* root){
    //make a local stack: 
    stack<Node*> myStack;

    //push root into local stack:
    myStack.push(root); 

    while(!myStack.empty()){
        Node* storageNode = myStack.top(); 
        myStack.pop(); 
        //process storage node: 
        cout << storageNode->val << endl; 
        if(storageNode!= nullptr){
            //push right
            if(storageNode->right)myStack.push(storageNode->right);
            //push left
            if(storageNode->left)myStack.push(storageNode->left);

        }

    }
}

int main(){
    //declare a tree structure
    //insert elements into the tree --> IS THIS THE RIGHT WAY? 
    Node* root = newNode(5);
    root->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(11);
 
    //pass the tree as a param to DFS function 
    DFS(root);
    return 0;
}