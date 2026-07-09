// Applicable only to DAG: Directed Acyclic Graph

// Refers to the linear ordering of vertices such that if
// there is an edge from u to v (u -> v) then u appears
// before v in that ordering

#include <bits/stdc++.h>
using namespace std;

class TopoSort {
    public:
        int n;
        vector<vector<int>> adj;
        vector<int> vis;
        stack<int> st;
        TopoSort(int N , vector<vector<int>> &adjList) {
            this->n = N;
            this->adj = adjList;
            vis.resize(n , 0);
        }

        void dfs(int node) {
            vis[node] = 1;
            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    dfs(it);
                }
            }
            st.push(node);
        }

        void build() {
            for(int i = 0 ; i < n ; i++) {
                if(!vis[i]) {
                    dfs(i);
                } 
            }
        }
};

void main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    TopoSort ts(n , adj);
    ts.build();
    vector<int> ans;
    while(!ts.st.empty()) {
        ans.push_back(ts.st.top());
        ts.st.pop();
    }
}