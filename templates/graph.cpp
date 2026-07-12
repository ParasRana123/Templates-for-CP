#include <bits/stdc++.h>
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
           
       }
};

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

class TopoSort {
    public:
        int n;
        vector<vector<int>> adj;
        vector<int> indegree;
        queue<int> q;
        vector<int> ans;

        TopoSort(int N , vector<vector<int>> &adjList) {
            this->n = N;
            this->adj = adjList;
            indegree.resize(n , 0);
            for(int u = 0 ; u < n ; u++) {
                for(auto &v: adj[u]) {
                    indegree[v]++;
                }
            }
        }

        void build() {
            for(int i = 0 ; i < n ; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto &it: adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }

        bool isCyclic() {
            if(ans.size() == n) return false;
            return true;
        }
};

int main() {

}