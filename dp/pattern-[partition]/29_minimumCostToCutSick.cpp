// Minimum cost to cut the stick
// QUESTION - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include<iostream>
#include<vector>
using namespace std;

// tabulation method - it will not give TLE and MLE
// copy the base case / condition
// write down the changing parameters
// copy the recurrence

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k=i; k<=j; k++){
                    int cost = cuts[j+1] - cuts[i-1];
                    int lenCost = cost + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, lenCost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][cuts.size()-2];
    }
};