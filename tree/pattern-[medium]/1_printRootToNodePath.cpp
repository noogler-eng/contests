// Print root to node path in binary tree

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int x){
            this->right = NULL;
            this->left = NULL;
            this->data = x;
        }
};

// left, root, right
// inorder traversal
// [1]
// [1, 2], checking left and right of 2
// [1, 2, 4], checking left and right of 4
// [1, 2], moving to right
// [1, 2, 5], checking left and right of 5
// [1, 2, 5, 6], checking left and right of 6
// [1, 2, 5], moving to right
// [1, 2, 5, 7], found
// time complexity o(N) - traverse all node
// space complexity o(H) - auxilliary space
bool helper(Node* root, vector<int> & ans, int x){
    if(root == NULL) return false;

    ans.push_back(root->data);
    if(root->data == x) return;
    // checking if the required node is found in either left or right
    if(helper(root->left, ans, x) || helper(root->right, ans, x)) return true;
    ans.pop_back();
    return false;
}


// level wise order of tree
// Input:Binary Tree: {1, 2, 3, 4, 5, -1, -1, -1, -1} Node: 7
// we have to print from root to node having value = 7
void printRootToNodePath(Node* root, int x){
    vector<int> path;
    helper(root, path, x);
}