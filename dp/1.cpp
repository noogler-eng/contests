// Maximum Amount of money Robot can make
// QUESTION -
// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/
// [Medium]

#include <iostream>
#include <vector>
using namespace std;

// standard problem -> max path sum
// advanced problem -> max path sum + at most k obstacles can be removed

// intution -
// moving down and moving right only

// options for robot
// 1. either go right or down
// 2. either gets roobed or use k
// down, right, k at max(can be 2) -> 0, 1
// dp[n][m][3]

// Maximum Amount of money Robot can make
// QUESTION -
// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/
// [Medium]

#include <iostream>
#include <vector>
using namespace std;

// standard problem -> max path sum
// advanced problem -> max path sum + at most k obstacles can be removed

// intution -
// moving down and moving right only

// options for robot
// 1. either go right or down
// 2. either gets roobed or use k
// down, right, k at max(can be 2) -> 0, 1
// dp[n][m][3]

class Solution {
public:
    int helper(int i, int j, int n, int m, int k,
               vector<vector<vector<int>>>& table, vector<vector<int>>& coins) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return INT_MIN;
        if (table[i][j][k] != INT_MIN)
            return table[i][j][k];
        if (i == n - 1 && j == m - 1) {
            int coin = coins[i][j];
            if (coin >= 0) {
                table[i][j][k] = coin;
            } else {
                if (k > 0) {
                    table[i][j][k] = max(0, coin);
                } else {
                    table[i][j][k] = coin;
                }
            }
            return table[i][j][k];
        }

        int coin = coins[i][j];
        int md = helper(i + 1, j, n, m, k, table, coins);
        int mr = helper(i, j + 1, n, m, k, table, coins);
        int best = max(md, mr);
        if (coin >= 0) {
            // coins will be consumes here
            // findig the max and adding them to memorization
            // atCurrStage = coin + max(down, right);
            return table[i][j][k] = best + coin;
        } else {
            if (k > 0) {
                // if there is a lifeline then
                // atCurrStage = max(taking lifeline, not taking lifeline)
                int rigth = helper(i + 1, j, n, m, k - 1, table, coins);
                int left = helper(i, j + 1, n, m, k - 1, table, coins);
                int useK = max(rigth, left);
                return table[i][j][k] = max(useK, best + coin);
            } else {
                return table[i][j][k] = best + coin;
            }
        }
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> table(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return helper(0, 0, n, m, 2, table, coins);
    }
};

