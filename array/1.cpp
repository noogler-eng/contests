// zig-zag grid traversall
// QUESTION - https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/
// [EASY]

#include<iostream>
#include<vector>
using namespace std;


// 1 2
// 3 4
// output -> 1, 4
// 1 2| 4 3
// 1 4

// 2 1
// 2 1
// 2 1
// output -> 2, 1, 2
// 2, 1|, 1, 2|, 2, 1
// 2, 1, 2

// 1 2 3
// 4 5 6
// 7 8 9
// output -> 1, 3, 5, 7, 9
// 1, 2, 3|, 6, 5, 4|, 7, 8, 9
// 1, 3, 5, 7, 9


// optmized approach
// time complexity o(N*N)
// space complexity o(N)
class Solution {
public:
    void reverse(vector<int> &level){
        int start = 0;
        int end = level.size()-1;
        while(start <= end){
            swap(level[start], level[end]);
            start++;
            end--;
        }
    }

    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;

        // we are kept checking for the reversal and checking if the start is from 0 or 1 index of row
        bool isLastTaken = false;
        for(int i=0; i<n; i++){
            vector<int> level = grid[i];
            if(i % 2 == 1) reverse(level);
            for(int j = isLastTaken == false ? 0: 1; j<m; j+=2){
                if(j == m-1) isLastTaken = true;
                else isLastTaken = false;
                ans.push_back(level[j]);
            }
        }

        return ans;
    }
};


// brute approch
// time complexity o(N*N)
// space complexity o(2N)
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &level){
        int start = 0;
        int end = level.size()-1;
        while(start <= end){
            swap(level[start], level[end]);
            start++;
            end--;
        }
    }

    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> main;
        vector<int> ans;

        for(int i=0; i<n; i++){
            vector<int> level = grid[i];
            if(i % 2 == 1) reverse(level);
            for(int j=0; j<m; j++){
                main.push_back(level[j]);
            }
        }

        for(int i=0; i<main.size(); i+=2){
            ans.push_back(main[i]);
        }

        return ans;
    }
};