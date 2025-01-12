// Shortest path in grid with obstacles elimination
// QUESTION - https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// [Hard]

#include<iostream>
#include<vector>
using namespace std;

// 1 -> obstacle
// 0 -> path
// up, down, left, right
// upper left corner -> lower right corner, we can remove at most K obstacles
// retuning minimum steps

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // If the grid is 1x1, no path computation is needed.
        if (n == 1 && m == 1) return 0;

        // Queue stores {{x, y}, {steps, obstacles_removed}}
        queue<pair<pair<int, int>, pair<int, int>>> q;
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        q.push({{0, 0}, {0, 0}});
        visited[0][0][0] = 1;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second.first;
            int obstacles_removed = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                    int new_obstacles_removed = obstacles_removed + grid[new_x][new_y];

                    if (new_obstacles_removed <= k && !visited[new_x][new_y][new_obstacles_removed]) {
                        visited[new_x][new_y][new_obstacles_removed] = 1;
                        q.push({{new_x, new_y}, {steps + 1, new_obstacles_removed}});

                        // If the destination is reached, return the steps.
                        if (new_x == n - 1 && new_y == m - 1) {
                            return steps + 1;
                        }
                    }
                }
            }
        }

        // If the destination is unreachable.
        return -1;
    }
};
