class Solution {
public:
    vector<int> parent, edgeCount, size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[py] = px;
            size[px] += size[py];
            edgeCount[px] += edgeCount[py] + 1;
        } else {
            edgeCount[px]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        edgeCount.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            unionSet(edge[0], edge[1]);
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i && size[i] * (size[i] - 1) / 2 == edgeCount[i]) {
                count++;
            }
        }

        return count;     
    }
};
