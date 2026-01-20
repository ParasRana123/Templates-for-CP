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

int getHeight(Node* node) {
    if(node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(Node* node) {
    if(Node == nullptr) {
        return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
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
    } else if(key > node->right) {
        node->right = insert(node->right , key);
    } else {
        return node;
    }
    node->height = 1 + max(getHeight(node->left) , getHeight(node->right));
    int b = getBalance(node);
    if(b > 1 && key < node->left->key) {
        return rightRotate(node);
    } 
    if(b < -1 && key > node->right->key) {
        return leftRotate(node);
    } 
    if(b > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(b < -1 && key < node->right->key) {
        node->right =- rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* curr = node;
    while(curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteNode(Node* root , int key) {
    if(root == nullptr) {
        return root;
    }
    if(key < root->key) {
        root->left = deleteNode(root->left , key);
    } else if(key > root->right) {
        root->right = deleteNode(root->right , key);
    } else {
        if((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if(temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
             root->key = temp->key;
             root->right = deleteNode(root->right, temp->key);
        }
    }
    if(root == nullptr) {
        return root;
    }
    int b = getBalance(root);
    if(b > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if(b > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(b < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if(b < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    root = deleteNode(root, 10);
    return 0;
}
