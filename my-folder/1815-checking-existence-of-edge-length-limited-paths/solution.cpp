class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        parent[rootX] = rootY;
        return true;
    }

private:
    vector<int> parent;
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    vector<pair<vector<int>, int>> sortedQueries(queries.size());
    for (size_t i = 0; i < queries.size(); i++) {
        sortedQueries[i] = {queries[i], i};
    }
    
    sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    sort(sortedQueries.begin(), sortedQueries.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
        return a.first[2] < b.first[2];
    });

    DSU dsu(n);
    vector<bool> answer(queries.size(), false);
    size_t edgeIdx = 0;
    for (const auto& queryPair : sortedQueries) {
        const auto& query = queryPair.first;
        int limit = query[2];

        while (edgeIdx < edgeList.size() && edgeList[edgeIdx][2] < limit) {
            dsu.unite(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
            edgeIdx++;
        }

        answer[queryPair.second] = (dsu.find(query[0]) == dsu.find(query[1]));
    }

    return answer;   
    }
};
