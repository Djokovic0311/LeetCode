class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(),  m = s2.length();
        int start = 0, len = INT_MAX, count = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[count]) count++;
            if(count == m) {
                int j = i;
                while (count > 0)
                {
                    if (s2[count - 1] == s1[j--])
                    {
                        count--;
                    }
                }
                j++;
                if(len > i-j+1){
                    len = i-j+1;
                    start = j;
                }
                i= j;
            }
        }
        if (len == INT_MAX) return "";
        return s1.substr(start, len);

    }
};