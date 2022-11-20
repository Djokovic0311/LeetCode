class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        queue<pair<int,int>> q;
        q.push({0,nums[0]});

        visited[0] = true;
        if(n == 1) return true;
        while(!q.empty()) {
            auto [idx, jump] = q.front();
            q.pop();
            for(int i = 1; i <= jump; i++) {
                int nidx = idx + i;
                // cout << idx << ' ' << jump << endl; 
                if(nidx < n && !visited[nidx]) {
                    visited[nidx] = true;
                    q.push({nidx, nums[nidx]});
                }
                if(visited[n-1]) return true;           
            }

        }
        return false;
    }
};
