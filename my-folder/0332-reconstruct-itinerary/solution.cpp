class Solution {
public:
    void dfs(string curr, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adj, vector<string> &ans) {
        while(adj[curr].size()) {
            string temp=adj[curr].top(); adj[curr].pop();
            dfs(temp, adj, ans);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto x: tickets) {
            adj[x[0]].push(x[1]);
        }
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
