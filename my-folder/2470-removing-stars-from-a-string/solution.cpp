class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '*')
                st.pop();
            else st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
