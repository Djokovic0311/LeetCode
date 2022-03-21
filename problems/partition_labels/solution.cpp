class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        
        if(n == 0) return ans;

        vector<int> last_pos (26, -1);
        
        for(int i=n-1; i>=0; --i) {
            if(last_pos[s[i]-'a'] == -1)
                last_pos[s[i]-'a'] = i;
        }
        int minp = -1, plen = 0;
        
        for(int i=0; i<n; ++i) {
            int lp = last_pos[s[i]-'a'];
            minp = max(minp, lp);
            ++plen;
            
            if(i == minp) {
                ans.push_back(plen);
                minp = -1;
                plen = 0;
            }
        }
        
        return ans;    
    }
};