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

int main() {

}