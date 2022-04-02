class Solution {
public:
    int cnt[26], maxcnt = 0, e = 0;
    int leastInterval(vector<char>& tasks, int n) {
        for (char c : tasks) cnt[c-'A']++;
        for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);
        for (int i = 0; i < 26; i++) 
            if (cnt[i] == maxcnt) e++;
        int k = tasks.size();
        return max(k, (maxcnt-1)*(n+1) + e);
    }
};
