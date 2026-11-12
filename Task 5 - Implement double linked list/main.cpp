#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#include <ostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Node{
    int data;
    Node* previous;
    Node* next;
} Node;

bool CreateNode(int val,int index,Node* root){
    for(int i = 0;i<index-1;i++){
        if(root->next != nullptr){
            root = root->next;
        }else{
            return false;
        }
    }
    Node* node = new Node;
    node->data = val;
    node->next = root->next;
    root->next = node;    
    return true;
}

void printLL(Node* root) {
    int index = 0;
    while (root != nullptr) {
        cout<< "[" << index<<"] = "<<root->data << " | ";
        root = root->next;
        index++;
    }
}

int main(){
    Node root = Node{.data=1};
    CreateNode(2, 1, &root);
    CreateNode(3, 1, &root);
    printLL(&root);
    cout<< endl;
    CreateNode(4, 1, &root);
    CreateNode(5, 1, &root);
    cout<< endl;
    printLL(&root);
}
