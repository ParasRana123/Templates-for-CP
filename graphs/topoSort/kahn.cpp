// Kahn's Algo is also known as Topological sort using BFS
// We here tak a indegeee and a queue for BFS.

#include <bits/stdc++.h>
using namespace std;

class Kahn {
    public:
        int n;
        vector<vector<int>> adj;
        vector<int> indegree;
        queue<int> q;
        Kahn(int N , vector<vector<int>> &adjList) {
            this ->n = N;
            this->adj = adjList;
            indegree.resize(n , 0);
            for(int u = 0 ; u < n ; u++) {
                for(int v: adj[u]) {
                    indegree[v]++;
                }
            }
        }

        vector<int> build() {
            vector<int> ans;
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
            return ans;
        }
};

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    Kahn k(n , adj);
    vector<int> topo = k.build();
    return 0;
}