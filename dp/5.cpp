// Longest common substring
// QUESTION - https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include<iostream>
#include<vector>
using namespace std;

// tabulation method
// if same not found then start all over again
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> table(n+1, vector<int>(m+1, 0));
        int len = 0;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                    len = max(len, table[i][j]);
                }else{
                    table[i][j] = 0;
                }
            }
        }

        return len;	
    }
};
