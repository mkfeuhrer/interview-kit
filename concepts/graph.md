### Introduction to Graphs

A graph is a non-linear data structure consisting of a set of vertices (or nodes) and a set of edges that connect pairs of vertices.

- **Vertices (V):** The points or nodes in the graph.
- **Edges (E):** The connections between vertices.

**Types of Graphs:**

- **Undirected Graph:** Edges have no direction. If there's an edge between A and B, you can travel from A to B and B to A.
- **Directed Graph (Digraph):** Edges have a direction. An edge from A to B means you can travel from A to B, but not necessarily from B to A.
- **Weighted Graph:** Edges have weights or costs associated with them (e.g., distance, time, cost).
- **Unweighted Graph:** Edges have no weights; the cost of traversing any edge is considered uniform (often 1).
- **Cyclic Graph:** Contains at least one cycle (a path that starts and ends at the same vertex).
- **Acyclic Graph:** Contains no cycles. A Directed Acyclic Graph is often abbreviated as DAG.
- **Connected Graph (Undirected):** There is a path between any two vertices.
- **Strongly Connected Graph (Directed):** There is a directed path from any vertex to any other vertex.
- **Tree:** A connected, undirected graph with no cycles. A tree with N vertices has exactly N-1 edges.
- **Forest:** A collection of disjoint trees.

### 2. Graph Representation

How we store a graph in memory affects the efficiency of algorithms. The two most common representations are:

- **Adjacency Matrix:** A 2D array where `matrix[i][j]` is 1 (or the weight) if there is an edge from vertex `i` to vertex `j`, and 0 (or infinity) otherwise.
  - **Pros:** O(1) time to check if an edge exists between two vertices. Simple to implement for dense graphs (many edges).
  - **Cons:** Requires O(V^2) space, which can be wasteful for sparse graphs (few edges).
- **Adjacency List:** An array or hash map where each index/key represents a vertex, and the value is a list of vertices adjacent to it. For weighted graphs, the list contains pairs of (adjacent vertex, weight).
  - **Pros:** Requires O(V + E) space, which is more efficient for sparse graphs. Easier to iterate through neighbors of a vertex.
  - **Cons:** O(degree(V)) time to check if an edge exists between two vertices.

**C++ Code Examples for Representation:**

**Adjacency Matrix (for unweighted, undirected graph):**

```cpp
#include <vector>

class AdjacencyMatrixGraph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    AdjacencyMatrixGraph(int V) : numVertices(V) {
        adjMatrix.resize(V, std::vector<int>(V, 0));
    }

    void addEdge(int src, int dest) {
        // For undirected graph
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    bool hasEdge(int src, int dest) {
        return adjMatrix[src][dest] == 1;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
```

**Adjacency List (for weighted, directed graph):**

```cpp
#include <vector>
#include <list>
#include <iostream>

class AdjacencyListGraph {
private:
    int numVertices;
    // Pair: {adjacent_vertex, weight}
    std::vector<std::list<std::pair<int, int>>> adjList;

public:
    AdjacencyListGraph(int V) : numVertices(V) {
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        // For directed graph
        adjList[src].push_back({dest, weight});
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ":";
            for (const auto& edge : adjList[i]) {
                std::cout << " -> (" << edge.first << ", " << edge.second << ")";
            }
            std::cout << std::endl;
        }
    }

    const std::list<std::pair<int, int>>& getNeighbors(int v) const {
        return adjList[v];
    }
};
```

### Code examples

- bfs.cpp
- dfs.cpp
- union_find.cpp
- kruskal.cpp
- topo_sort.cpp
- prims.cpp
- dijkstra.cpp

### Important Graph Problem Patterns and Topics

- **Grid Problems:** Many problems on 2D grids can be modeled as graph problems where grid cells are vertices and adjacent cells have edges. BFS is often used for shortest paths on unweighted grids, DFS for traversals/connected components.
- **Connectivity:** Problems involving checking if a graph is connected, finding connected components (BFS/DFS), or strongly connected components (Tarjan's or Kosaraju's algorithm - more advanced).
- **Bipartite Graphs:** A graph where vertices can be divided into two disjoint sets such that every edge connects a vertex in one set to a vertex in the other set. Can be checked using BFS or DFS (coloring the graph).
- **Graph Coloring:** Assigning labels (colors) to vertices such that no two adjacent vertices have the same color.
- **Network Flow:** Problems involving the flow of some commodity through a network (graph). (More advanced: Ford-Fulkerson, Edmonds-Karp).
- **Articulation Points and Bridges:** Vertices or edges whose removal increases the number of connected components. (More advanced).

### Relevant LeetCode Problems

Here's a list of representative problems on LeetCode covering the topics we discussed:

**BFS/DFS:**

- [733. Flood Fill](https://leetcode.com/problems/flood-fill/) (Grid, DFS/BFS)
- [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) (Grid, DFS/BFS)
- [133. Clone Graph](https://leetcode.com/problems/clone-graph/) (Graph Copying, BFS/DFS)
- [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/) (Grid, DFS/BFS)
- [1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/) (Grid, DFS/BFS)
- [542. 01 Matrix](https://leetcode.com/problems/01-matrix/) (BFS, multi-source)
- [841. Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) (DFS/BFS, connectivity)
- [797. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) (DFS/Backtracking)

**Shortest Path:**

- [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/) (Dijkstra)
- [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) (BFS or Bellman-Ford variation)
- [1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) (Floyd-Warshall or multiple Dijkstras)
- [1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) (Dijkstra variation on a grid, or Union-Find/Kruskal idea)

**MST:**

- [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) (Kruskal or Prim - implicitly a graph problem)

**Topological Sort:**

- [207. Course Schedule](https://leetcode.com/problems/course-schedule/) (Topological Sort or Cycle Detection using DFS/BFS)
- [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) (Topological Sort, return the order)
- [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) (Topological Sort idea, removing leaves iteratively)

**Union-Find:**

- [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/) (Union-Find or DFS/BFS for connected components)
- [130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) (DFS/BFS or Union-Find)
- [1202. Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/) (Union-Find to find connected components of indices)
- [721. Accounts Merge](https://leetcode.com/problems/accounts-merge/) (Union-Find on email addresses)

**Cycle Detection:**

- [207. Course Schedule](https://leetcode.com/problems/course-schedule/) (As mentioned above)
- [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) (As mentioned above)
- [261. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) (Union-Find or DFS/BFS + edge count)

**Bipartite:**

- [785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) (BFS or DFS coloring)

### Tips for Graph Problems in Interviews

1.  **Understand the Problem:** Clearly identify if it's a graph problem and what type of graph it is (directed/undirected, weighted/unweighted).
2.  **Draw the Graph:** For small examples, draw the graph to visualize the connections.
3.  **Choose Representation:** Decide whether Adjacency Matrix or Adjacency List is more suitable based on the graph's density (sparse vs. dense) and the operations needed. Adjacency List is generally preferred for sparse graphs which are common in interview problems.
4.  **Select the Right Algorithm:**
    - **Traversal (visit all nodes):** BFS or DFS.
    - **Shortest Path (unweighted):** BFS.
    - **Shortest Path (non-negative weights):** Dijkstra.
    - **Shortest Path (with negative weights, no negative cycles):** Bellman-Ford.
    - **All-Pairs Shortest Path:** Floyd-Warshall.
    - **MST:** Prim's or Kruskal's.
    - **Dependency/Ordering:** Topological Sort (requires a DAG).
    - **Connectivity/Components:** BFS, DFS, or Union-Find.
    - **Cycle Detection:** DFS (different variations for directed/undirected).
5.  **Handle Visited Nodes:** Use a `visited` set or array to prevent infinite loops in traversals and ensure each node is processed once per traversal. For directed graphs, you might need additional states (e.g., `visiting` for cycle detection).
6.  **Edge Cases:** Consider graphs with a single node, no edges, disconnected components, etc.
7.  **Complexity Analysis:** Be prepared to state the time and space complexity of your chosen algorithm.
8.  **Implement Clearly:** Write clean, readable code. Use meaningful variable names.
9.  **Talk Through Your Logic:** Explain your thought process to the interviewer.

This covers the essential topics for graph algorithms in coding interviews. Practice implementing these algorithms from scratch and work through the suggested LeetCode problems.
