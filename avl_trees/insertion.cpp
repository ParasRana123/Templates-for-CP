#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node * node) {
    if(node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(Node* N) {
    if(N == nullptr) {
        return 0;
    }
    return getHeight(Node->left) - getHeight(Node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
    x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
    return x;
}

Node* leftRotate(Node * x) {
    Node* y = x->left;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
    y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
    return y;
}

Node* insert(Node* node , int key) {
    if(node == nullptr) {
        return new Node(key);
    }
    if(key < node->key) {
        node->left = insert(node->left , key);
    } else if(key > node->key) {
        node->right = insert(node->right , key);
    } else {
        return node;
    }
    node->height = 1 + max(getHeight(node->left) , getHeight(node->right));
    int balance = getBalance(node);
    // left left case
    if(balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    // right-right case
    if(balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    // left-right case
    if(balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        rightRotate(node);
    }
    // right-left case
    if(balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        leftRotate(node);
    }
    return node;
} 

int main() {
    Node* root = nullptr;
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    return 0;
}
