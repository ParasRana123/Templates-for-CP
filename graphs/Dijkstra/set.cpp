#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> dijkstra(int V , vector<vector<pair<int , int>>> &adj , int src) {
    set<pair<int , int>> st;
    vector<int> dist(V , 1e18);
    st.insert({0 , src});
    dist[src] = 0;
    while(!st.empty()) {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto &it: adj[node]) {
            int edgeW = it.first;
            int adjNode = it.second;
            if(edgeW + dis < dist[adjNode]) {
                if(dist[adjNode] != 1e18) {
                    st.erase({dist[adjNode] , adjNode});
                }
                dist[adjNode] = edgeW + dis;
                st.insert({dist[adjNode] , adjNode});
             }
        }
    }
    return dist;
}