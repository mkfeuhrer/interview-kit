# include <bits/stdc++.h>
using namespace std;

/*
 * Union-Find (Disjoint Set Union)
 * Manages a partition of a set into non-overlapping subsets.
 * Supports two main operations:
 * - Union: Merges two subsets into one.
 * - Find: Determines which subset a particular element belongs to.
 * Finding connected components.
 * Time Complexity: Amortized O(1) for both operations with path compression and union by rank.
 * Space Complexity: O(n) for the parent array.
*/

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    // sample graph
    UnionFind uf(5);
    uf.unionSets(0, 1);
    uf.unionSets(0, 2);
    uf.unionSets(1, 3);
    uf.unionSets(2, 4);
    
    cout << "Is 0 and 3 connected? " << (uf.find(0) == uf.find(3)) << endl;
    cout << "Is 0 and 4 connected? " << (uf.find(0) == uf.find(4)) << endl;
    return 0;
}