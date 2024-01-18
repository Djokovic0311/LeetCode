class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);
        for(auto seq : sequences) {
            int size = seq.size();
            int from = seq[0];
            for(int i = 1; i < size; ++i) {
                int to = seq[i];
                ++indegree[to];
                graph[from].push_back(to);
                from = to;
            }
        }
        queue<int> q;
        q.push(nums[0]);

        if(indegree[0]) return false;
        int curr = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(nums[curr++] != node) return false;
            bool found_next = false;
            for(auto neighbor : graph[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    if(found_next) return false;
                    found_next = true;
                    q.push(neighbor);
                }
            }
        }
        
        return curr == n;
    }
};
