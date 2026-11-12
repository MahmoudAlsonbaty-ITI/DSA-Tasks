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

class MyStack {
public:
    Node* LastElement;
    MyStack() {
        LastElement = nullptr;
    }
    
    void push(int x) {
        Node* newLast = new Node;
        newLast->data = x;
        newLast->previous = LastElement;
        LastElement = newLast;
    }
    
    int pop() {
        Node* old = LastElement;
        int val = old->data;
        LastElement = old->previous;
        delete old;
        return val;
    }
    
    int top() {
        return LastElement->data;
    }
    
    bool empty() {
        return LastElement == nullptr;
    }
};
void printLL(Node* root) {
    int index = 0;
    while (root != nullptr) {
        cout<< "[" << index<<"] = "<<root->data << " | ";
        root = root->next;
        index++;
    }
}

int main(){
    MyStack st;
    st.push(5);
    cout << st.top()<<endl;
    st.push(10);
    cout << st.top()<<endl;
    st.pop();
    cout << st.top()<<endl;
    st.pop();
    if(st.empty()) cout<< "Stack Empty" <<endl;
}
