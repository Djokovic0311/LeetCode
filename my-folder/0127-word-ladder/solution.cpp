class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        set<string> st;
        for(auto w : wordList)
            st.insert(w);
        
        queue<string> q;
        q.push(beginWord);

        int d = 0;

        while(!q.empty()) {
            int n = q.size();
            d++;

            while(n--) {
                string curr = q.front();
                q.pop();

                int l = curr.length();
                for(int i = 0; i < l; i++) {
                    string tmp = curr;
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == tmp[i]) continue;
                        tmp[i] = c;
                        if(tmp == endWord) return d+1;
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
