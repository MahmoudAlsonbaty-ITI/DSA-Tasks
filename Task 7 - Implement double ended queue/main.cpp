#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
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

class MyDoubleEndedQueue {
public:
    Node* LastElement;
    Node* FirstElement;
    int size = 0;
    MyDoubleEndedQueue() {
        LastElement = nullptr;
        FirstElement = nullptr;
    }
    
    void push_back(int x) {
        Node* node= new Node;
        node->data = x;
        node->next = FirstElement;
        node->previous = nullptr;
        if (FirstElement!= nullptr) FirstElement->previous = node;
        FirstElement = node;
        if(size == 0) LastElement =FirstElement;
        size++;
    }
    void push_front(int x) {
        Node* node= new Node;
        node->data = x;
        node->previous = LastElement;
        node->next = nullptr;
        if (LastElement != nullptr) LastElement->next = node;
        LastElement = node;
        if(size == 0) FirstElement =LastElement;
        size++;
    }
    
    int pop_back() {
        if(size == 0) return -1;
        Node* old = FirstElement;
        int val = old->data;
        FirstElement = FirstElement->next;
        if (FirstElement != nullptr) FirstElement->previous = nullptr;
        else LastElement = nullptr; 
        delete old;
        size--;
        return val;
    }
    int pop_front() {
        if(size == 0) return -1;
        Node* old = LastElement;
        int val = old->data;
        LastElement = LastElement->previous;
        if (LastElement != nullptr) LastElement->next = nullptr;
        else FirstElement = nullptr;
        delete old;
        size--;
        return val;
    }
    
    int front() {
        return LastElement->data;
    }
    int back() {
        return FirstElement->data;
    }

    bool empty() {
        return  size ==0;
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
    MyDoubleEndedQueue q;
    q.push_front(1);
    q.push_back(2);
    cout << q.front()<<endl;
    cout << q.back()<<endl;
    q.push_front(0);
    q.push_back(4);
    cout << q.front()<<endl;
    cout << q.back()<<endl;
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    if(q.empty()) cout<< "Queue Empty" <<endl;
}
