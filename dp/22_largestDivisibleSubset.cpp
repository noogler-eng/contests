// Largest divisible subset
// QUESTION - https://leetcode.com/problems/largest-divisible-subset/description/
// [Medium]

#include<iostream>
#include<vector>
using namespace std;

// arr = {1, 16, 7, 8, 4}
// now in subset they can be in any order
// either arr[i] % arr[j] == 0 or arr[j] % arr[i] == 0
// here pair like {1, 4, 8, 16}
// arr = {1, 16, 7, 8, 4}
// arr = {1, 4, 7, 8, 16}, sorted it
// {1, 4, 8, 16}

// arr = {1, 2, 3}
// starting from 2
// {1, 2}

// now it becomes longest divisble subsequence
// arr = {1, 4, 7, 8, 16}
// {1, 4, }


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);

        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) hash[i] = i;

        int maxi = 0, parent;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                parent = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[parent]);
        while(hash[parent] != parent){
            parent = hash[parent];
            ans.push_back(nums[parent]);
        }

        return ans;
    }
};