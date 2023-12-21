class Solution {
    bool checkValidParenthesis(string s)
    {
        int cnt = 0;
        for(auto ch : s)
        {
           cnt += (ch == '(');
           cnt -= (ch == ')');
           if(cnt < 0) return false; //means ')' exceeds '(' in a prefix of s
        }
     return (cnt == 0); //check if all '(' are cancelled with ')' or not
    }

    int getMinimumRemovals(string s)
    {
        stack<char> st;
        for(auto ch : s)
        {
            if(ch != '(' && ch != ')') continue; //skip lowercase alphabets
           if(!st.empty() && st.top() == '(' && ch == ')')
            st.pop();
           else
            st.push(ch); //push invalid characters
        }
     return st.size(); //stack's size will tell the no. of invalid characters
    }

    void solve(string s, int removalsLeft, vector<string>& ans, unordered_map<string,bool>& isPresent)
    {
        if(isPresent.count(s) > 0) return; //must step to avoid TLE
        isPresent[s] = true;
        if(removalsLeft == 0) //after making required removals
        {
            if(checkValidParenthesis(s)) { //if current string is valid
                ans.push_back(s); //then, include it in answer
            }
         return;
        }
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != '(' && s[i] != ')') continue; //skip lowercase alphabets
            //skip current character (i.e. character at ith index)
            string newString = s.substr(0,i) + s.substr(i+1);
            solve(newString,removalsLeft-1,ans,isPresent);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_map<string,bool> isPresent;
        int minRemovals = getMinimumRemovals(s);
        solve(s,minRemovals,ans,isPresent);
        return ans;
    }
};
