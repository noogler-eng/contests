// Minimize the maximum edge weight graph
// QUESTION - https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

#include<iostream>
#include<vector>
using namespace std;

// intiution - directly graph
// questions conditon - 
// 1. node 0 must be rechable from all other node
// 2. the maximum edge weight in resulting graph must be minimized
// 3. each node has at most threshold outing edges

// Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
// adj list, graph is directed
// 0 -> []
// 1 -> [{0, 1}]
// 2 -> [{0, 2}, {1, 1}]
// 3 -> [{0, 1}]
// 4 -> [{3, 1}]
// here the edge {2, 0, 2} is removed so minimum max weight = 1

// brute force 
// for each node checking 0 is rechable or not (bfs) -> tc o(n) * o(n+m) ~ o(N*N)
// constraint -> 1 < n < 10^5
// means N*N not work here -> NlogN, logN, N can works here

// reversing the graph
// 0->1, 2, 3, 4,.... checking
// min distance (with them find the maxWeight who only got selected)

class Solution {
public:
    void bfs(int src, int n, vector<int>& dis, int wt,
        vector<vector<pair<int, int>>>& adj) {
        queue<int> q;
        vector<bool> isVis(n, false);
        q.push(0);
        dis[0] = 0;
        isVis[0] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto i : adj[node]) {
                int new_node = i.first;
                int new_wt = i.second;
                if (new_wt > wt)
                    continue;
                if (!isVis[new_node]) {
                    isVis[new_node] = true;
                    q.push(new_node);
                    dis[new_node] = 1;
                }
            }
        }
    }

    bool check(vector<vector<pair<int, int>>>& adj, int n, long long mid) {
        vector<int> d(n, INT_MAX);
        bfs(0, n, d, mid, adj);
        for (int i = 0; i < n; i++) {
            if (d[i] == INT_MAX)
                return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // reversing the direction of graph
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[v].push_back({u, wt});
        }

        int low = 0, high = 1e6 + 1, ans = 1e6 + 1;
        while (low <= high) {
            int mid = (high + (low - high) / 2);
            if (check(adj, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // node is not rechanble means return -1
        if (ans > 1e6)
            return -1;
        else
            return ans;
    }
};


// easy way and optmized version 
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> graph(n);
            
        for(auto edge:edges) {
            int u = edge[0],
                v = edge[1],
                w = edge[2];

            graph[v].push_back({u, w});
        }
        
        int l = 1, r = 1000000, ans = -1;
        
        while(l<=r) {
            int mid = (l + r) >> 1;
            
            vector <int> vis(n);
            queue <int> q;
            q.push(0);
            vis[0]=1;
            int ct = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto [neg,w]:graph[node]) {
                    if(vis[neg] || w>mid) continue;
                    vis[neg]=1;
                    q.push(neg);
                    ++ct;
                }
            }

            if(ct==n) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};