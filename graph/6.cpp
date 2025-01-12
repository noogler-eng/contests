// Shortest path with alternating color
// QUESTION - https://leetcode.com/problems/shortest-path-with-alternating-colors/
// [Medium]

#include<iostream>
#include<vector>
using namespace std;

// intiution 
// BFS - mainly used to find out the shortest distance
// BFS + constraint (checking the path)

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<redEdges.size(); i++){
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adj[u].push_back({v, true});
        }

        for(int i=0; i<blueEdges.size(); i++){
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adj[u].push_back({v, false});
        }

        // contains node and color of current edge
        queue<pair<int, bool>> q;
        // shortes path for both blue and the red
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[0][0] = 0;
        dist[0][1] = 0;

        // true -> red and false -> blue
        q.push({0, true});
        q.push({0, false});

        while(!q.empty()){
            int node = q.front().first;  
            bool currentColor = q.front().second;
            q.pop();

            for(auto neighbourNodes: adj[node]){
                int new_node = neighbourNodes.first;
                bool new_color = neighbourNodes.second;
                // if the new node is unvisited and new_color and prev color is not same then only
                if( dist[new_node][new_color] == INT_MAX && new_color != currentColor){
                    dist[new_node][new_color] = dist[node][currentColor] + 1;
                    q.push({new_node, new_color});
                }
            }
        }

        vector<int> ans(n);
        // here what are we trying to do making out the maximum from travelling both the path
        for(int i=0; i<n; i++){
            ans[i] = (dist[i][0] == INT_MAX && dist[i][1] == INT_MAX) ? -1:  min(dist[i][0], dist[i][1]);
        }

        return ans;
    }
};