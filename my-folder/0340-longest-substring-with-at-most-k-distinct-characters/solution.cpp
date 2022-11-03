class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        int res = 0;
        unordered_map<char, int> count; // track number occurances of each char between 'l' & 'r'
        for(int l = 0, r = 0; r < s.length(); ++r) 
        {
            ++count[s[r]];
            while(count.size() > k)
            {
                if(--count[s[l]] == 0) count.erase(s[l]);
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
