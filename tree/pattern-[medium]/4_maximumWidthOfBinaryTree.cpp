// Maximum width of binary trr

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// width of binary tree - max number of node any level can have
// [1, 2, 3, 4, 5, -1, 6]
// here last level contains at max 4 nodes so width is 4 but view from bottom should
// look like 4

class TreeNode{
    public:
        int data;
        TreeNode* right;
        TreeNode* left;
        TreeNode(int x){
            this->right = NULL;
            this->left = NULL;
            this->data = x;
        }
};

// this is how we number the tree
// in order to prevent overflow as (2 * i + 1) may be overflowed
// 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long val = q.front().second - mmin;
                if (i == 0)
                    first = val;
                if (i == size - 1)
                    last = val;

                q.pop();

                if (node->left)
                    q.push({node->left, val * 2 + 1});
                if (node->right)
                    q.push({node->right, val * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};