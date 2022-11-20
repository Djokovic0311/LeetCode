class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        vector<int> freq(256, 0);
        int i = 0, j = 0;
        int count = 0;
        int res = 0;

        for(; i < n; i++) {
            if(freq[s[i]]==0) {
                count++;
            }
            freq[s[i]]++;
            if(count > 2) {
                while(count > 2 && j < n && freq[s[j]] > 0) {
                    // cout << count << endl;
                    
                    freq[s[j]]--;
                    if(j < n && freq[s[j]] == 0) count--;
                    j++;
                    
                }
                
                
            }
            // cout << j << ' ' << i << endl;
            res = max(res, i-j+1);
            
        }
        return res;
    }
};