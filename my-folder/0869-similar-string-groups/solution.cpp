class Solution {
public:
bool areSimilar(const std::string &s1, const std::string &s2) {
    int diff = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            ++diff;
        }
    }
    return diff == 2 || diff == 0;
}

void dfs(const std::vector<std::string> &strs, std::vector<bool> &visited, int node) {
    visited[node] = true;
    for (int i = 0; i < strs.size(); ++i) {
        if (!visited[i] && areSimilar(strs[node], strs[i])) {
            dfs(strs, visited, i);
        }
    }
}


int numSimilarGroups(vector<string>& A) {
    int groups = 0;
    std::vector<bool> visited(A.size(), false);
    for (int i = 0; i < A.size(); ++i) {
        if (!visited[i]) {
            dfs(A, visited, i);
            ++groups;
        }
    }
    return groups;
}
};
