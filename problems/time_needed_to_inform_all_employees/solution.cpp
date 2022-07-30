class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push(make_pair(headID,0));
        int mx = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int head=q.front().first;
                int timeTaken=q.front().second;
                q.pop();
                int dur=informTime[head]+timeTaken;
                mx=max(mx,dur);
                for(auto it:mp[head]) {
                    q.push(make_pair(it,dur));
                } 
            }
        }
        return mx;
    }
};