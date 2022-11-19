class Solution {
public:
    string swap(string str, int i, int j) {
        string ans = str;
        ans[i] = str[j];
        ans[j] = str[i];
        return ans;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        string des = "123450";
        string src = "";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                src += to_string(board[i][j]);
        }

        queue<pair<string,int>> q;
        vector<vector<int>> dirs {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        q.push(make_pair(src,0));

        unordered_set<string> st;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto [str, level] = q.front();
                q.pop();
                if(str == des) {
                    return level;
                }
                int idx;
                for (int i = 0; i < str.size(); ++i)
                    if (str[i] == '0')
                        idx = i;
                for(auto d : dirs[idx]) {
                    string nstring = swap(str,idx, d);
                    if(st.find(nstring) != st.end()) {
                        continue;
                    }
                    else {
                        q.push(make_pair(nstring, level + 1));
                        st.insert(nstring);
                    }
                }
            }
        }
        return -1;
    }
};