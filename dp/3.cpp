// Print all longest common subsequence
// QUESTION - https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

#include<iostream>
#include<set>
#include<vector>
using namespace std;


// intution 
// longest common subseq -> dp, two-pointers

class Solution {
  public:

    void helper(string &s1, string &s2, int i, int j, set<string> &longestCommonsSubseqs, string str, vector<vector<int>> &dp, int len){
        if (i == 0 || j == 0) {
            if (str.length() == len) {
                reverse(str.begin(), str.end());
                longestCommonsSubseqs.insert(str);
            }
            return;
        }

        if(str.length() == len) {
            reverse(str.begin(), str.end());
            longestCommonsSubseqs.insert(str);
            return;
        }
        
        if (s1[i-1] == s2[j-1]) {
            helper(s1, s1, i-1, j-1, longestCommonsSubseqs, str + s1[i-1], dp, len);
        } else {
            // If current LCS length equals LCS length by moving up
            if (dp[i-1][j] >= dp[i][j-1]) {
            helper(s1, s1, i-1, j, longestCommonsSubseqs, str, dp, len);
            }
            // If current LCS length equals LCS length by moving left
            if (dp[i][j-1] >= dp[i-1][j]) {
            helper(s1, s1, i, j-1, longestCommonsSubseqs, str, dp, len);
            }
        }
    }

    vector<string> all_longest_common_subsequences(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> table(n+1, vector<int>(m+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1] == text2[j-1]){
                    table[i][j] = 1 + table[i-1][j-1];
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        int len = table[n][m];
        set<string> longestCommonsSubseqs;
        helper(text1, text2, n, m, longestCommonsSubseqs, "", table, len);

        return vector<string>(longestCommonsSubseqs.begin(), longestCommonsSubseqs.end());
    }
};


