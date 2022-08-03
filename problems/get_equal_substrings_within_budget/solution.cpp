class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i = 0, j;
        int res = INT_MIN;
        for(j = 0; j < n; j++) {
            if((maxCost-=abs(t[j]-s[j])) < 0)
            {maxCost += abs(t[i] - s[i++]);
                res = max(res, j-i);
            }
        }
        return j-i;
    }
};