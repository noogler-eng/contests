// Print all longest common subsequence

#include<iostream>
#include<set>
#include<vector>
using namespace std;


// intution 
// longest common subseq -> dp, two-pointers

class Solution {
  public:
    string longest_common_subsequences(string text1, string text2) {
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
        int index = len-1;
        int i=n, j=m;
        string ans = "";
        while(i > 0 && j > m){
            if(text1[i-1] == text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }else if(table[i][j-1] > table[i-1][j]){
                j--;
            }else{
                i--;
            }
        }

        return ans;
    }
};


