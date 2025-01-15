// Lowest common ancestor

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

// time complexity o(N)
// space complexity o(H)
// tree = [1, 2, 3, 4, 5, 8, 9, -1, -1, 6, 7, -1, -1, -1, -1]
Node* helper(Node* root, Node* a, Node* b){
    if(root == NULL || root == a || root == b) return root;

    Node* left = helper(root->left, a, b);
    Node* right = helper(root->right, a, b);

    if(left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        // if both left and right are not null
        return root;
    }

}

int lowestCommonAncestor(Node* root, Node* a, Node* b){
    return helper(root, a, b)->data; 
}