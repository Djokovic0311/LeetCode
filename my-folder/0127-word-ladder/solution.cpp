class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<string> q;
        int steps = 0;
        q.push(beginWord);
        set<string> st(wordList.begin(), wordList.end());
        while(!q.empty()) {
            int sz = q.size();
            steps++;
            for(int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                int l = curr.length();
                for(int j = 0; j < l; j++) {
                    string tmp = curr;
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == curr[j]) continue;
                        tmp[j] = c;
                        if(tmp == endWord && st.find(endWord) != st.end()) return steps+1;
                        if(st.find(tmp) != st.end()) {
                            q.push(tmp);
                            st.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
