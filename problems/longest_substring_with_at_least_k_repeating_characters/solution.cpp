class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n<k) return 0;
        unordered_map<char,int> freq;
        for(auto a:s) ++freq[a];
        int i=0;
        while(i<n and freq[s[i]]>=k) ++i;
        if(i==n) return i;
        if(i==0) return (n>1)?longestSubstring(s.substr(1,n-1),k):0;
        return max(longestSubstring(s.substr(0,i),k),longestSubstring(s.substr(i,s.size()-i),k));
    }
};