// you are given the root of binary tree with N nodes where each node in the tree has some no of coins, 
// and there are N coins total. In one move we may choose two adj nodes and move one coin from one node 
// to another. your task is to return the number of moves required to make every node have exactly one coin
// [Razorpay]

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left = NULL;
        Node* right = NULL;
        Node(int data){
            this->data = data;
        }
};

int moves = 0;
// time complexity o(N), travsering each and every node
// space complexity o(N) as auxilliar space
int distributeCoins(Node* root){
    if(root == NULL) return 0;
    
    int left = distributeCoins(root->left);
    int right = distributeCoins(root->right);

    // due to this abs case of -1 handled as
    // left node has -1 and right node has -1 then both abs(-1) + abs(-1) = 2
    // 2 moves required to make them 1 coin as -1 represnts null or no coin
    moves += abs(left) + abs(right);
    return root->data + left + right - 1;
}
