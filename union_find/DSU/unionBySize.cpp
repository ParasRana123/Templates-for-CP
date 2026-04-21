// Connected components in a graph using DSU by Method: Union by size

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class DisjointSet {
    public:
        vector<int> parent , size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for(int i = 0 ; i < n ; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionBySize(int u , int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
    int connectedComponents(int n , vector<vector<int>> &edges) {
        DisjointSet dsu(n);
        for(auto &e: edges) {
            int u = e[0];
            int v = e[1];
            dsu.unionBySize(e[0] , e[1]);
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