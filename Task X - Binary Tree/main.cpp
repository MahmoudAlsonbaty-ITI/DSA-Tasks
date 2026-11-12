#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#include <ostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode* parent;
} TreeNode;

TreeNode* CreateNode(int val,TreeNode* parent){
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = val;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->parent = parent;
    return node;
}

TreeNode* createBinaryTree(){
    // TreeNode* root1 = CreateNode(0, NULL);
    // root1->leftChild = CreateNode(1, root1);
    // root1->rightChild = CreateNode(2, root1);
    // root1->leftChild->leftChild = CreateNode(3, root1->leftChild);
    // root1->leftChild->rightChild = CreateNode(4, root1->leftChild);
    // root1->rightChild->leftChild = CreateNode(5, root1->rightChild);
    // root1->rightChild->rightChild = CreateNode(6, root1->rightChild);
    // return root1;

    cout<<"Enter the Node value or -1 for an empty node"<<endl;
    int val;
    cin >> val;
    TreeNode* root = CreateNode(val,  NULL);
    queue<TreeNode*> q;
    q.push(root);
    //      0
    //    1   2
    //  3  4  5  6
    //
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if(curr->leftChild == NULL){
            cout << "Enter -1 for an empty node or the left child of " << curr->data <<"or -2 to end the tree"<<endl;
            int d ;
            cin >> d;
            if(d == -2){
                break;
            }
            if(d != -1){
                curr->leftChild = CreateNode(d, curr);
                left = curr->leftChild;

            }
        }
        if(curr->rightChild == NULL){
            cout << "Enter -1 for an empty node or the right child of or -2 to end the tree " << curr->data <<"or -2 to end the tree"<<endl;
            int d ;
            cin >> d;
            if(d == -2){
                break;
            }
            if(d != -1){
                curr->rightChild = CreateNode(d, curr);
                right = curr->rightChild;
            }
        }
        if(left != NULL){
            q.push(left);
        }    
        if(right != NULL){
            q.push(right);
        }    
    }
    return root;
}

int countTreeNodes(TreeNode* root){
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr != NULL){
            count++;
            cout << " " << curr->data;
            if(curr->leftChild != NULL) q.push(curr->leftChild);
            if(curr->rightChild != NULL) q.push(curr->rightChild);
        }

    }
    return count;
}
int countTreeLeafs(TreeNode* root){
    int count = 0;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        if(curr != NULL){
            // count++;
            cout << " " << curr->data;
            if(curr->leftChild != NULL) s.push(curr->leftChild);
            if(curr->rightChild != NULL) s.push(curr->rightChild);
            if(curr->leftChild == NULL && curr->rightChild == NULL) count++;
        }
    }
    return count;
}
//This function was made by Ai for visualization purposes
void printTreeHelper(TreeNode* root, string prefix, bool isLeft, bool isRoot) {
    if (root == nullptr) {
        return;
    }

    // Print the right subtree first (so it appears on top)
    printTreeHelper(root->rightChild, prefix + (isLeft ? "│   " : "    "), false, false);

    // Print the current node
    cout << prefix;
    if (!isRoot) {
        cout << (isLeft ? "└── " : "┌── ");
    }
    cout << root->data << endl;

    // Print the left subtree (appears on the bottom)
    printTreeHelper(root->leftChild, prefix + (isLeft ? "    " : "│   "), true, false);
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }
    printTreeHelper(root, "", false, true);
}

int main(){
    TreeNode* root = createBinaryTree();
    cout<< endl;
    printTree(root);
    cout<< endl;
    int nodes = countTreeNodes(root);
    cout<< endl;
    int leafs = countTreeLeafs(root);
    cout << endl << "NODES : " <<nodes;
    cout << endl << "LEAFS : "<<leafs;
}
