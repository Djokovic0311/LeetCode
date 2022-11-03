class Solution {
public:
    string swap(string str, int i, int j) {
        string ans = str;
        ans[i] = str[j];
        ans[j] = str[i];
        return ans;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        string dest = "123450";
        string src = "";
        for (int i = 0; i < n * m; ++i)
            src += to_string(board[i / m][i % m]);
        cout << src;
        queue<pair<string, int>> que;
        que.push(make_pair(src, 0));
        unordered_set<string> map;
        vector<vector<int>> dirs {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        while (!que.empty()) {
            int size = que.size();
            while (size-- > 0) {
                pair<string, int> temp = que.front(); que.pop();
                string str = temp.first;
                int level = temp.second;
                if (str.compare(dest) == 0)
                    return level;
                int idx = -1;
                for (int i = 0; i < str.size(); ++i)
                    if (str[i] == '0')
                        idx = i;
                for (int dir: dirs[idx]) {
                    string temp1 = swap(str, idx, dir);
                    if (map.find(temp1) != map.end())
                        continue;
                    que.push(make_pair(temp1, level + 1));
                    map.insert(temp1);
                }
            }
        }
        return -1;
    }
};
