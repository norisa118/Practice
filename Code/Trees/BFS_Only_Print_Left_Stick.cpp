#include <queue>
#include <iostream>
#include <utility>      // std::pair, std::make_pair

using namespace std;

struct Node {
    int val;
    int level;
    struct Node *left, *right;
};

// helper function to create a node
Node* newNode(int data)
{
    // dynamically allocating memory
    Node* temp = new Node();
    temp->val = data;
    temp->level = -1; 
    temp->left = temp->right = NULL;
    return temp;
}

void BFS(Node* root){
    //make a local stack: 
    queue<Node*> myQueue;

    //push root into local stack:
    root->level = 1; 
    myQueue.push(root); 

    int printThis = false;

    int currentLvl = -1;
    int prevLvl = -1;
    while(!myQueue.empty()){
        Node* storageNode = myQueue.front(); 
        currentLvl = storageNode->level;
        cout << "popping : " << myQueue.front()->level << endl;
        myQueue.pop(); 
        //process storage node: 
        if(currentLvl==prevLvl+1 || storageNode->level == 1) cout << storageNode->val << " , " << storageNode->level << endl; 
        if(storageNode!= nullptr){
            
            //push left
            if(storageNode->left){
                storageNode->left->level = storageNode->level+1;
                myQueue.push(storageNode->left);
            }
            //push right
            if(storageNode->right){
                storageNode->right->level = storageNode->level+1;
                myQueue.push(storageNode->right);
            }
            
            prevLvl = storageNode->level; 

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
    BFS(root);
    return 0;
}