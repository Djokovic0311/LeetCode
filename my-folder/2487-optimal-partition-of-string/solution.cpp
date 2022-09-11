class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        set<char> st;
        int i = 0, j = 0;
        int res = 0;
        while(i < n) {
            while(j < n) {
                st.insert(s[j]);
                if(st.size() == j-i+1) {
                    j++;
                }
                else break;
            }
            res++;
            st.clear();
            i = j;
        }
        return res;
    }
};
