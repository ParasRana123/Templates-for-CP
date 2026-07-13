#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
       int n;
       vector<int> parent;
       vector<int> size;
        DisjointSet(int N) {
          this->n = N;
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

int kruskal(int n , vector<vector<int>> &vec) {
    DisjointSet dsu(n);
    int sum = 0;
    for(auto &it: vec) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        int parent_u = dsu.findUltimateParent(u);
        int parent_v = dsu.findUltimateParent(v);
        if(parent_u != parent_v) {
            dsu.unionBySize(u , v);
            sum += wt;
        }
    }
    return sum;
}

int main() {
    // pass vec of the form {{u1 , v1 , w1} , {u2 , v2 , w2} , ....}
    // sort vec based on the weights
    // Only then pass it to the above function
    // n is the no. of nodes/vertices
}