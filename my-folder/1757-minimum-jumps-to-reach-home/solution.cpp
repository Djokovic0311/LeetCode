class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int res = 0;
        int n = forbidden.size();
        unordered_map<int,int> mp;
        for(int f: forbidden) {
            mp[f]++;
        }
        // Queue will store the Position, Number of hops and 
	  // a bool variable that will denote if the last hop was in
	  // forward direction or backward (True: forward, False: backward)
        queue<pair<int, pair<int, bool>>> q;  
        q.push({0, {0, true}});

        while(!q.empty()) {
            auto node = q.front();
            int currPos = node.first, ans = node.second.first;
            bool canGoBackwards = node.second.second;
            q.pop();
            if(currPos == x) return ans;
            if(mp.find(currPos) != mp.end()) continue; 
            mp[currPos]++;
            int forward = currPos + a, backward = currPos - b;
            if(canGoBackwards and backward >= 0) {
                q.push({backward, {ans + 1, false}});
            }
            if(forward <= 2000 + a + b ){
                q.push({forward, {ans + 1, true}});
            }
        }
        return -1;
    }
};
