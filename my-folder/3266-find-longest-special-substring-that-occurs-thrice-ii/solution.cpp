class Solution {
public:
    int cal(vector<int> freq) {
        map<int, int, greater<int>> mp;
        for(int f : freq) {
            mp[f]++;
        }

        auto it = mp.begin();
        int curr_len = it->first;
        int curr_count = it->second;
        while(curr_len) {
            // cout << curr_len << " " << curr_count << endl;
            
            if(curr_count >= 3) return curr_len;
            else {
                curr_len--;
                curr_count += 1;
                if(mp.find(curr_len) != mp.end()) {
                    // cout << "found" << curr_len<< endl;
                    curr_count += mp[curr_len];
                }
            }
            
        }
        return -1;
    }
    int maximumLength(string s) {
        vector<vector<int>> freq(26);
        int n = s.length();
        int i = 0, j = 0;
        int res = -1;
        while(i < n && j < n) {
            int count = 0;
            while(j < n && s[i] == s[j]) {
                j++;
            }
            freq[s[i]-'a'].push_back(j-i);
            i = j;
        }
        for(int i = 0; i < 26; i++) {
            
            if(freq[i].size() != 0) {
                // cout << i << endl;
                int tmp = cal(freq[i]);
                res = max(tmp, res);                
            }

        }

        return res;
    }
};
