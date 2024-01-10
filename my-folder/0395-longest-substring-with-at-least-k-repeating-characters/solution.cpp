class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        vector<int> o_freq(26, 0);
        int unique = 0;
        int res = 0;

        for(char c : s) {
            o_freq[c-'a']++;
        }
        for(int f : o_freq) {
            if(f != 0)
                unique++;
        }


        for(int curr_unique = 1; curr_unique <= unique; curr_unique++) {
            int start = 0, end = 0;
            vector<int> freq(26, 0);
            int cnt = 0, cntk = 0;
            while(end < n) {
                if(cnt <= curr_unique) {
                    int idx = s[end] - 'a';
                    if(freq[idx] == 0) {
                        cnt++;
                    } 
                    freq[idx]++;
                    if(freq[idx] == k) {
                        cntk++;
                    }
                    end++;
                } else {
                    int idx = s[start] - 'a';
                    if(freq[idx] == k) {
                        cntk--;
                    }
                    freq[idx]--;
                    if(freq[idx] == 0) {
                        cnt--;
                    }
                    start++;
                }
                if(cntk == curr_unique && cnt == curr_unique) {
                    cout << start << " " << end << endl;
                    res = max(res, end - start);
                    cout << res << endl;
                }
            }
        }
        return res;
    }
};
