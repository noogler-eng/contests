// Longest string chain
// QUESTION - https://leetcode.com/problems/longest-string-chain/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// {"a", "b", "ba", "bca", "bda", "bcda"}
// {"a", "ba", "bca"}
// {"a", "ba", "bda"}
// {"b", "ba", "bda"}


class Solution {
public:
    bool isDiffOne(string word1, string word2){
        int i=0, j=0;
        if(word1.length() - word2.length() != 1) return false;
        while(i !=word1.length() && j != word2.length()){
            if(word1[i] == word2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(j == word2.length()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isDiffOne(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};