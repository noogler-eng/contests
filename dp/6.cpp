// Longest Palindromic Subsequence
// QUESTION - https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include<iostream>
#include<vector>
using namespace std;

string reverse(string s){
    int start = 0;
    int end = s.length()-1;
    while(start <= end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

int longestPalindromeSubseq(string s) {
    string r = reverse(s);
    int n = s.length();
    
    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1] == r[j-1]){
                // when both match
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
        
    return table[n][n];
}