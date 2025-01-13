// Print longest common subseq
// QUESTION - https://www.naukri.com/code360/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<iostream>
#include<vector>
using namespace std;

// tabulization method
string findLCS(int n, int m,string &s, string &t){
    vector<vector<string>> table(n+1, vector<string>(m+1, ""));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s[i-1] == t[j-1]){
                table[i][j] = table[i-1][j-1] + s[i-1];
            }else{
				if(table[i-1][j].length() >= table[i][j-1].length()){
					table[i][j] = table[i-1][j];
				}else{
					table[i][j] = table[i][j-1];
				}
            }
        }
    }

    return table[n][m];	
}

// recursive method
// it will show tle
string helper(int n, int m, string s, string t, int i1, int i2, vector<vector<string>>& table){
    if(i1 == n || i2 == m) return "";
    if(table[i1][i2] != "") return table[i1][i2];

    if(s[i1] == t[i2]){
        return table[i1][i2] = s[i1] + helper(n, m, s, t, i1+1, i2+1, table);
    }else{
        string op1 = helper(n, m, s, t, i1+1, i2, table);
        string op2 = helper(n, m, s, t, i1, i2+1, table);

        if(op1.length() >= op2.length()){
            return table[i1][i2] = op1;
        }else{
            return table[i1][i2] = op2;
        }
    }
    return table[i1][i2];
}

string findLCS(int n, int m,string &s, string &t){
    vector<vector<string>> table(n+1, vector<string>(m+1, ""));
    return helper(n, m, s, t, 0, 0, table);
}