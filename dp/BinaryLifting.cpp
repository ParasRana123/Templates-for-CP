// Binary Lifting: Variation of DP on Trees
// Binary Lifting preprocesses a tree so you can jump upward by powers of 2, allowing ancestor and LCA queries in O(log n) time.

#include <bits/stdc++.h>
using namespace std;

struct BinaryLifting {
    int n;
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    BinaryLifting(int N) {
        n = N;
        LOG = 0;
        while((1 << LOG) <= n) LOG++;
        adj.assign(n , {});
        up.assign(n , vector<int>(LOG , -1));
        depth.assign(n , 0);
    }

    void addEdge(int u , int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node , int parent) {
        up[node][0] = parent;
        for(int child: adj[node]) {
            if(child == parent) continue;
            depth[child] = depth[node] + 1;
            dfs(child , node);
        }
    }

    void buildAncestorTable() {
        for(int j = 1 ; j < LOG ; j++) {
            for(int i = 0 ; i < n ; i++) {
                if(up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    void init(int root = 0) {
        dfs(root , -1);
        buildAncestorTable();
    }

    int kthAncestor(int node , int k) {
        for(int j = 0 ; j < LOG ; j++) {
            if(k & (1 << j)) {
                node = up[node][j];
                if(node == -1) break;
            }
        }
        return node;
    }

    int lca(int u , int v) {
        if(depth[u] < depth[v]) {
            swap(u , v);
        }
        u = kthAncestor(u , depth[u] - depth[v]);
        if(u == v) return u;
        for(int j = LOG - 1  ; j >= 0 ; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int distance(int u , int v) {
        int w = lca(u , v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

void main() {
    BinaryLifting bl(8);
    bl.addEdge(0, 1);
    bl.addEdge(0, 2);
    bl.addEdge(1, 3);
    bl.addEdge(1, 4);
    bl.addEdge(2, 5);
    bl.addEdge(2, 6);
    bl.addEdge(4, 7);
    bl.init(0);
    bl.dfs(0, -1);
    bl.buildAncestorTable();
    cout << bl.kthAncestor(7,2);
    cout << bl.lca(7,3);
}   