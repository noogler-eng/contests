// Longest biotonic subseq
// QUESTION - https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// [Medium]

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// A subsequence of array is called Bitonic if it is first strictly increasing, 
// then strictly decreasing. Return the maximum length of bitonic subsequence
// Input: n = 5, nums[] = [1, 2, 5, 3, 2]

int LongestBitonicSequence(int n, vector<int> &nums) {
    vector<int> dp1(n, 1), dp2(n, 1);
    // first for increasing then for decreaing

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i] && dp1[i] < dp1[j] + 1){
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(nums[j] < nums[i] && dp2[i] < dp2[j] + 1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if (dp1[i] > 1 && dp2[i] > 1) {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
    }

    return ans;
}