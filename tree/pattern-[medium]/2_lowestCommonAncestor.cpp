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

bool getPath(Node* root, vector<int> &path, int x){
    if(root == NULL) return false;

    path.push_back(root->data);
    if(root->data == x) return true;
    if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true;
    path.pop_back();
    return false;
}

// lowestCommonAncestor(4, 7)
// ancestor will come in both path surely
// path of 4 = [1, 2, 4]
// path of 7 = [1, 2, 5, 7]
// last common part as like 2 is here last matched ans = 2

// tree = [1, 2, 3, 4, 5, 8, 9, -1, -1, 6, 7, -1, -1, -1, -1]
// lowest common acestor is just first common ancestor of both from bottom
// brute force
// time complexity o(N*2)
// space complexity o(H*2)
int lowestCommonAncestor(Node* root, int a, int b){
    vector<int> path1;
    vector<int> path2;

    getPath(root, path1, a);
    getPath(root, path2, b);

    int i=0, j=0;
    int ans = root->data;
    while(path1[i] == path2[j]){
        ans = path1[i];
        i++;
        j++;
    }

    return ans;
}