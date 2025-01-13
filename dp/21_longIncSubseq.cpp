// Longest increasing subsequence
// QUESTION - https://leetcode.com/problems/longest-increasing-subsequence/

#include<iostream>
#include<vector>
using namespace std;


// arr = {1, 7, 8, 4, 5, 6, -1, 9}
// temp = {1}
// temp = {1, 7}
// temp = {1, 7, 8}
// temp = {1, 4, 8}
// temp = {1, 4, 5}
// temp = {1, 4, 5, 6}
// temp = {-1, 4, 5, 6}
// temp = {-1, 4, 5, 6, 9} 
// it gives always the length of this
// here the temp array is not LIS at the end of day
// we just counting the length of longest increasing subseq

// time complexity o(NLogN)
// space complexity o(N)
class Solution {
public:  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > temp[temp.size()-1]){
                temp.push_back(nums[i]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};