class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] > rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) {
            rank[rootY]++;
        }

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    DSU dsu_alice(n + 1), dsu_bob(n + 1);
    int removed_edges = 0;

    // Process type 3 edges (common to both Alice and Bob)
    for (const auto& edge : edges) {
        if (edge[0] == 3) {
            if (!dsu_alice.merge(edge[1], edge[2])) {
                removed_edges++;
            } else {
                dsu_bob.merge(edge[1], edge[2]);
            }
        }
    }

    // Process type 1 and 2 edges (specific to Alice and Bob)
    for (const auto& edge : edges) {
        if (edge[0] == 1) {
            if (!dsu_alice.merge(edge[1], edge[2])) {
                removed_edges++;
            }
        } else if (edge[0] == 2) {
            if (!dsu_bob.merge(edge[1], edge[2])) {
                removed_edges++;
            }
        }
    }

    // Check if both Alice and Bob can fully traverse the graph
    int alice_components = 0, bob_components = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu_alice.find(i) == i) alice_components++;
        if (dsu_bob.find(i) == i) bob_components++;
    }

    if (alice_components > 1 || bob_components > 1) {
        return -1;
    }

    return removed_edges;        
    }
};
