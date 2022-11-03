class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) 
        {
            vector<string> res;
            unordered_set<string> visited;
            queue<string> q;
            q.push(s);
            visited.insert(s);
            while(!q.empty())
            {
                int size = q.size();
                for(int i = 0; i < size; ++i)
                {
                    string str = q.front(); q.pop();
                    char ch_remove = isValid(str);
                    if(ch_remove == 1) res.push_back(str);

                    if(res.size()) continue; // all our results are on this level - no need to populate queue

                    for(int j = 0; j < str.length(); ++j)
                    {
                        if(str[j] == ch_remove)
                        {
                            string snew = str.substr(0, j) + str.substr(j+1);
                            if(!visited.count(snew)) 
                            {
                                q.push(snew);
                                visited.insert(snew);
                            }
                        }
                    }
                }
                if(res.size()) break;
            }
            return res;
        }

    protected:
        // returns 1 if valid; char to be removed otherwise
        char isValid(string& s)
        {
            int count = 0;
            for(char c : s)
            {
                if(c == '(') ++count;
                else if(c == ')') 
                    if(count > 0) --count;
                    else return ')';
            }
            return count == 0 ? 1 : '(';
        }
};