// Minimum cost to cut the stick
// QUESTION - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include<iostream>
#include<vector>
using namespace std;


// arr = {1, 3, 4, 5}, n = 7

// cost is the length of stick we cut
// we can cut in any order

// if sticks are seprated then we can do independently
// if sticks are not seprated then we try all 
// make it recurssion tree which will make it more better understanding

// arr = {0, 1, 3, 4, 5, 7}
// i = 0 and j = 5
// cost = (7 - 0) + helper(0, 0, cuts) + helper(k+1, 5, cuts)
// cost = (7 - 1) + helper(2, 2, cuts) + helper(k+1, 5, cuts)
// ..........




// without memorization - gives TLE
// with memorization - gives MLE
class Solution {
public:
    int helper(int i, int j, vector<int> cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k=i; k<=j; k++){
            // this is current removal cost
            int cost = cuts[j+1] - cuts[i-1];
            // this is for left half and right half
            int lenCost = cost + helper(i, k-1, cuts, dp) + helper(k+1, j, cuts, dp);
            mini = min(mini, lenCost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(1, cuts.size()-2, cuts, dp);
    }
};
