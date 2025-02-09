/*
You are provided with an array that represents the preorder traversal of a Binary Search Tree (BST).
Your task is to construct the BST from the given preorder array and compute the total sum of the corner elements (the leftmost and rightmost nodes) of every level in the tree.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

Node* constructBST(vector<int>& preorder) {
    Node* root = NULL;
    for (int val : preorder) {
        root = insert(root, val);
    }
    return root;
}

int user_logic(Node* root) {
    Node *curr=root;
    queue<Node*> q;
    int sum=0;
    if(!root) return 0;
    q.push(curr);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node *temp=q.front();
            if(i==0 || i==size-1)
             sum+=temp->val;
            q.pop();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    Node* root = constructBST(preorder);
    int result = user_logic(root);
    cout << result << endl;
    return 0;
}
