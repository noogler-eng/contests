// Matrix chain multiplication
// QUESTION - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

#include<iostream>
#include<vector>
using namespace std;

int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) dp[i][i] = 0;


    // i goes from 1 to n
    // j goes from n-1 to i
    // we reverse this loop to ensure that smaller problem solved before larger one
    for(int i=n-1; i>=1; i--){
        for(int j = i+1; j<n; j++){
            int mini = INT_MAX;
            for(int k=i; k<j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}