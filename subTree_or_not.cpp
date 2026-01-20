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

static int index2 = -1;
Node* buildTreePreOrder2(vector<int> preOrder){
    index2++;
    if(preOrder[index2]==-1){
        return NULL;
    }
    Node* root = new Node(preOrder[index2]);
    root->left = buildTreePreOrder2(preOrder);
    root->right = buildTreePreOrder2(preOrder);
    
    return root;
}

bool is_identical(Node* p, Node* q){
/*  p           q          result
===================================

   NULL      Not NUll      false
  Not NULL    NULL         false
   NULL       NULL         true
*/
/*
    // if(p == NULL && q == NULL){
    //     return true;
    // }
    // else if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
    //     return false;
    // }
*/ 
    if(p==NULL || q==NULL){
        return p==q;
    }
    return is_identical(p->left, q->left) && is_identical(p->right, q->right) && (p->data == q->data);
}


bool is_subtree(Node* root, Node* subroot){
    if(root == NULL || subroot ==NULL){
        return root == subroot;  
    }
    if(root->data == subroot->data && is_identical(root, subroot)){
        return true;
    }
    return is_subtree(root->left, subroot) || is_subtree(root->right, subroot);
}



int main(){
//     //building tree from pre order notation
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> preOrder2 = {3, 4, -1, -1, 5, -1, -1};

/*              preOder
                   1
                 /   \
               2       3
                      / \
                     4   5 
*/
/*              preOder2
                       3
                      / \
                     4   5
*/
    Node* root = buildTreePreOrder(preOrder);
    Node* subroot = buildTreePreOrder2(preOrder2);
    
    bool subtree = is_subtree(root, subroot);
    if(subtree){
        cout << "subtree!" << endl;
    }
    else{
        cout << "Not subtree!" << endl;
    }

    return 0;
}