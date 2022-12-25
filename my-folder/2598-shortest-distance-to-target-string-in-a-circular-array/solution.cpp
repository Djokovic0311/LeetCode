class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        int res = 100;
        
        for(int i = 0;i < n; i++) {
            if(words[i] == target) {
                // cout << i << ' ';
                res = min(res, abs(i-startIndex));
                res = min(res, n-abs(i-startIndex));
                // cout << res << endl;
            }
        }
        return res == 100 ? -1 : res;
    }
};
