// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
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

static int ind = -1;
Node* buildTreePreOrder(vector<int> preOrder){
    ind++;
    if(preOrder[ind] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[ind]); 

    root->left = buildTreePreOrder(preOrder);
    root->right = buildTreePreOrder(preOrder);

    return root;
}

Node* buildTreePostOrder(vector<int> postOrder){
    ind++;
    if(postOrder[ind] == -1){
        return NULL;
    }
    Node* root  = new Node(postOrder[ind]);
    root->right = buildTreePostOrder(postOrder);
    root->left = buildTreePostOrder(postOrder);

    return root;
}

Node* buildTreeInOrder(vector<int> inOrder, int l, int r){
    int idx = (l+r)/2;
    if(inOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(inOrder[idx]);
    root->left = buildTreeInOrder(inOrder, l, idx-1);
    root->right = buildTreeInOrder(inOrder, idx+1, r); 

    return root; 
}

void pre(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
void indorder(Node* root){
    if(root == NULL){
        return;
    }
    indorder(root->left);
    cout << root->data << " ";
    indorder(root->right);
}
void post(Node* root){
    if(root == NULL){
        return;
    }
    post(root->left);
    post(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    
    while(q.size()){
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}
int main(){
//     //building tree from pre order notation
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};

/*                 1
                 /   \
               2       3
              / \     / \
             4   5   6   7 
*/
    Node* root  = buildTreePostOrder(preOrder);

    
    // //building tree from post order notation
    // vector<int> postOrder = {-1, -1, 4, -1, -1, 5, 2, -1, -1, 6, -1, -1, 7, 3, 1};
    // reverse(postOrder.begin(), postOrder.end());
    // Node* root = buildTreePostOrder(postOrder);

    // //building tree from in order notation
    // vector<int> inOrder = {-1, 4, -1, 2, -1, 5, -1, 1, -1, 6, -1, 3, -1, 7, -1};

    // Node* root = buildTreeInOrder(inOrder, 0, inOrder.size()-1);
    
    cout << "Pre order: ";
    pre(root);
    cout << endl;

    cout << "inorder: "; 
    indorder(root); 
    cout << endl;

    cout << "Post order: ";
    post(root);
    cout << endl;

    cout << "Level Order: "; 
    levelOrder(root);
    cout << endl;

    return 0;
}