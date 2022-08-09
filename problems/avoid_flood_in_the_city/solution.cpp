class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> mp;
        int n = rains.size();
        vector<int> ans;
        set<int> st;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(rains[i] == 0) {
                st.insert(i);
                ans.push_back(1);
            }
            else 
            {
                if(mp.find(rains[i]) != mp.end()) {
                int x = rains[i];
                auto it = st.lower_bound(mp[x]);
                
                //cout<<x<<" "<<*it<<" ";
                    
                if(it == st.end())
                    return {};
                
                ans[*it] = rains[i];
                st.erase(*it);
            }
                mp[rains[i]] = i;
                ans.push_back(-1);
        }
    }   
        return ans;
    }
};