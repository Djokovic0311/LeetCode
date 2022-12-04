class Solution {
public:
    // adj matrix by roads
    vector<pair<int, int>> adj[100001];
    
    int minScore(int n, vector<vector<int>>& roads) {
        // build adj matrix
        for(auto i : roads) {
            adj[i[0]].emplace_back(make_pair(i[1], i[2]));
            adj[i[1]].emplace_back(make_pair(i[0], i[2]));
        }
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.emplace(1);
        int ans = INT_MAX;
        for(; !q.empty(); q.pop()) {
            int from = q.front();
            vis[from] = 1;
            for(auto [to, val] : adj[from]) {
                if(!vis[to]) {
                    ans = min(ans, val);
                    q.emplace(to);
                }
            }
        }
        return ans;
        
    }
};
