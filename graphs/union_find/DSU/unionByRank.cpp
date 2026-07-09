#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class DisjointSet {
    public:
        vector<int> parent , rank;
        DisjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1 , 0);
            for(int i = 0 ; i < n ; i++) {
                parent[i] = i;
            }
        }

        int findUltimateParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u , int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
    public:
        int connectedComponents(int n , vector<vector<int>> &edges) {
            DisjointSet dsu(n);
            for(auto &e: edges) {
                int u = e[0];
                int v = e[1];
                dsu.unionByRank(u , v);
            }
            int cnt = 0;
            for(int i = 0 ; i < n ; i++) {
                if(dsu.findUltimateParent(i) == i) {
                    cnt++;
                }
            }
            return cnt;
        }
};