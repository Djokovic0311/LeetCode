class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        stack<pair<char,int>> stk;
        for(int i = 0; i < n; i++) {
            if(!stk.empty() && stk.top().first == s[i]) {
                auto tmp = stk.top();
                stk.pop();
                if(tmp.second+1 < k)
                    stk.push({tmp.first, tmp.second+1});
            } else {
                stk.push({s[i],1});
            }
        }
        string res;
        while(!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            while(tmp.second--){
                res.push_back(tmp.first);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
