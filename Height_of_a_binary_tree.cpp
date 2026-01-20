#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int index = -1;
Node* buildTreePreOrder(vector<int> preOrder){
    index++;
    if(preOrder[index]==-1){
        return NULL;
    }
    Node* root = new Node(preOrder[index]);
    root->left = buildTreePreOrder(preOrder);
    root->right = buildTreePreOrder(preOrder);
    
    return root;
}

int height(Node* curr){
    if(curr == NULL){
        return 0;
    }
    return 1 + max(height(curr->left), height(curr->right));
}

int main(){
    
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
/*                 1
                 /   \
               2       3
              / \     / \
             4   5   6   7 
*/
    Node* root = buildTreePreOrder(preOrder);
    
    cout << "height: " <<  height(root) << endl;

    return 0;
}