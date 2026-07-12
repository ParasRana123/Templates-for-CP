Some Important Points to keep in mind:

- Detecting a cycle in an undirected graph → Use DSU (or DFS). If find(u) == find(v), a cycle exists.
TC: O(E · α(N)).

- k-th ancestor queries on a tree → Use Binary Lifting.
Preprocessing: O(N log N)
Per Query: O(log N).

- LCA (Lowest Common Ancestor) queries → Use Binary Lifting.
Preprocessing: O(N log N)
Per Query: O(log N).

- Minimum distance between two nodes in a tree → Use LCA + depth array (Binary Lifting):
dist(u,v) = depth[u] + depth[v] - 2*depth[lca(u,v)].
Per Query: O(log N).

- Dependencies, prerequisites, ordering constraints, build order → Use Topological Sort (Kahn's Algorithm or DFS).
TC: O(V + E).

- Detecting a cycle in a directed graph → Use Topological Sort; if topo.size() < n, a cycle exists.
TC: O(V + E).

- Shortest path in an unweighted graph or grid → Use BFS.
TC: O(V + E).

- Shortest path with multiple starting points → Use Multi-Source BFS.
TC: O(V + E).

- Shortest path when edge weights are only 0 and 1 → Use 0-1 BFS (deque).
TC: O(V + E).

- Shortest path with positive weights → Use Dijkstra.
TC: O((V + E) log V).

- Shortest path with negative weights / detecting negative cycle → Use Bellman-Ford.
TC: O(VE).

- Longest path / counting paths in a DAG → Use Topological Sort + DP.
TC: O(V + E).

- Two groups, enemies/friends, alternating colors → Check if the graph is Bipartite using BFS/DFS coloring.
TC: O(V + E).

- Strongly Connected Components (SCC) → Use Kosaraju or Tarjan.
TC: O(V + E).