class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        // vector<vector<pair<int,int>>> adj(n, vector<int>(n,0));
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            // adj[e[0]].push_back(make_pair(e[1],vals[e[1]]));
            // adj[e[1]].push_back(make_pair(e[0],vals[e[0]]));
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        int mx = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int tmp = vals[i];
            int tmpk = 0;
            priority_queue<int> pq;
            for(int j : adj[i]) {
                // cout << j << ' ';
                pq.push(vals[j]);
            }
            // cout << endl;
            
            while(tmpk < k && !pq.empty()) {
                tmpk++;
                if(pq.top() > 0) {
                    tmp += pq.top();
                    pq.pop();                    
                }
                else break;

            }
            // cout << i << ' ' << tmp << endl;
            // cout << endl;
            mx = max(mx, tmp);
        }
        return mx;
    }
};
