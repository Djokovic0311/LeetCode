class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char,int> mp;
        for(char c : t) {
            mp[c]++;
        }
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.        
        int formed = 0;
        // Number of unique characters in t, which need to be present in the desired window.
        int unique = mp.size();
        unordered_map<char,int> windowCounts;
        // ans list of the form (window length, left, right)
        vector<int> ans = {-1,0,0};
        while(r < s.length()) {
            char c = s[r];
            windowCounts[c]++;
            if(mp[c] == windowCounts[c]) {
                formed++;
            }
            while(l <= r && formed == unique) {
                c = s[l];
                if(ans[0] == -1 || r-l+1<ans[0]) {
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }
                windowCounts[c]--;
                if(windowCounts[c] < mp[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "": s.substr(ans[1], ans[2]-ans[1]+1);
    }
};
