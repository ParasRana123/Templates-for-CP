#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Will be storing the nodes as well as the respective distances/cost between them in the adjacency list
// will use a min heap of {node , dist} --> Push the initial node 0 with a dist of 0 into the heap
// also we will maintain a dist vector alongside --> will initialise the src node with a dist of 0 and all the other nodes with a initail dist of infinite(INT_MAX)

vector<int> dijkstra(int V , vector<vector<pair<int,int>>> &adj , int S) {
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    vector<int> dist(V);
    for(int i = 0 ; i < V ; i++) {
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0 , S});
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]) {
            int edgeWeight = it.first;
            int adjNode = it.second;
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode] , adjNode});
            }
        }
    }
    return dist;
}

int main() {

}