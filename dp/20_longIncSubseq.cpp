// Longest Increasing subseq
// QUESTION - https://leetcode.com/problems/longest-increasing-subsequence/
// [Medium]

#include<iostream>
#include<vector>
using namespace std;

// arr = [5, 4, 11, 1, 16, 8]
// dp[] = [1, 1, 2, 1, 3, 2]
// longest = 3
// dp[i] = longest subseq unti ith index

// [5, 4, 11, 1, 16, 8]
// [1, 1, ...]
// if anything less then present then take the maimum value of the lowe one
// if no one less then is there then take directly 1


class Solution {
public:  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        // time complexity o(N*N)
        // space complexity o(N)
        for(int i=0; i<n; i++){
            // checking all the previous indexes
            // can be a previous part of mine
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // yes, it can be part of this
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int maxi = 0;
        for(int i=0; i<n; i++) maxi = max(maxi, dp[i]);
        return maxi;
    }
};

// print the longest subseq also
class Solution {
public:  
    void reverse(vector<int> &nums){
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    pair<int, vector<int>> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i=0; i<n; i++) hash[i] = i;

        // time complexity o(N*N)
        // space complexity o(N)
        for(int i=0; i<n; i++){
            // checking all the previous indexes
            // can be a previous part of mine
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // yes, it can be part of this
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
        }

        // from above we got the hash array 
        // {0, 1, 1, 3, 2, 1}

        int maxi = 0, parent;
        for(int i=0; i<n; i++) {
            if(dp[i] > maxi) {
                maxi = dp[i];
                parent = i;
            }
        }

        vector<int> ans;
        ans.push_back(parent);
        while(parent != hash[parent]){
            parent = hash[parent];
            ans.push_back(parent);
        }

        // now reverse the ans for subseq
        reverse(ans);

        return {maxi, ans};
    }
};