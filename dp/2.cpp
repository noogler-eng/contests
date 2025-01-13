// longest common subsequnce 
// QUESTION - https://leetcode.com/problems/longest-common-subsequence/

// intiution
// common subseq -> dp (mainly) , (two-pointers)

#include<iostream>
#include<vector>
using namespace std;


// tabulation maethod
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
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

        return table[n][m];
    }
};


// recurssion method
// time complexity o(n*m)
// space complexity o(n*m) + o(n+m) addition memory space
class Solution {
public:
    int helper(string text1, string text2, int i1, int i2){
        if(i1 == text1.size() || i2 == text2.size()) return 0;
        if(text1[i1] == text2[i2]) return helper(text1, text2, i1+1, i2+1) + 1;
        else return max(helper(text1, text2, i1+1, i2), helper(text1, text2, i1, i2+1));
    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length(); 
        return helper(text1, text2, 0, 0);
    }
};


// memorization method
// time complexity o(n*m)
// space complexity o(n*m)
class Solution {
public:
    int helper(string text1, string text2, int i1, int i2, vector<vector<int>> &table){
        if(i1 == text1.size() || i2 == text2.size()) return 0;
        if(table[i1][i2] != -1)  return table[i1][i2];
        if(text1[i1] == text2[i2]) return table[i1][i2] = helper(text1, text2, i1+1, i2+1, table) + 1;
        else return table[i1][i2] = max(helper(text1, text2, i1+1, i2, table), helper(text1, text2, i1, i2+1, table));
    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length(); 
        vector<vector<int>> table(n, vector<int>(m, -1));
        return helper(text1, text2, 0, 0, table);
    }
};