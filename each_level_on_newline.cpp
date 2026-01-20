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

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (q.size())
    {
        Node* curr = q.front();
        q.pop();
        if(curr != NULL){
            cout << curr->data << " ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        else{
            if(q.size()){
                cout << endl;
                q.push(NULL);
            }
            else{
                break;
            }
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
    Node* root = buildTreePreOrder(preOrder);
    
    levelOrder(root);

    return 0;
}