// Count longest increasing subsequnce
// QUESTION - https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        // it is obivous that there are 1 pathway exists
        vector<int> count(n, 1);

        int maxLen = 0;
        for(int i=0; i<n; i++){
            // checking all the previous indexes
            // can be a previous part of mine
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // yes, it can be part of this
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }else if(dp[i] == 1 + dp[j]){
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(maxLen == dp[i]){
                ans+=count[i];
            }
        } 

        return ans;
    }
};