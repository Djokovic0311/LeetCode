class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, vector<string>> mp;
        for(auto t : tickets) {
            mp[t[0]].push_back(t[1]);
        }

        for(auto& [_, dests] : mp) {
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> res;
        stack<string> stk;
        stk.push("JFK");

        while(!stk.empty()) {
            string curr = stk.top();
            if(mp.find(curr) != mp.end() && !mp[curr].empty()) {
                stk.push(mp[curr].back());
                mp[curr].pop_back();
            } else {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;

    }
};
