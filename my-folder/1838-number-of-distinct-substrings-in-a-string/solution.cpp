class Solution {
public:
    int countDistinct(string s) {
        int l = s.length();
        set<string> visited;
        for(int i = 0; i < l; i++) {
            string tmp = "";
            for(int j = i; j < l; j++) {
                tmp += s[j];
                visited.insert(tmp);
            }
        }
        return visited.size();
    }
};
