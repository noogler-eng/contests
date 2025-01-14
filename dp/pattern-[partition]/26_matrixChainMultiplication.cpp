// Matrix chain multiplication
// QUESTION - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

#include<iostream>
#include<vector>
using namespace std;

// A -> n * m
// B -> m * o
// C -> n * o

// no of operation required -> n * m * o
// arr = {10, 20, 30, 40, 50}, n = 5;
// returns the minimum multiplication from 1 to 4

// it shows TLE
// time complexity - exponential

// time complexity of memoization o(N^3)
// space complexity o(N^2) + o(N) auxilliary stack space
// in order to apply memorization
// see changing variables first
int helper(int i, int j, vector<int> arr, vector<vector<int>> &table){
    if(i == j) return 0;
    if(table[i][j] != -1) return table[i][j];

    int mini = INT_MIN;
    // the are k number of partitons like
    // k = 1, 2, 3, 4
    for(int k=i; k<j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + helper(i, k, arr, table) + helper(k+1, j, arr, table);
        mini = min(mini, steps);
    }

    return table[i][j] = mini;
}


