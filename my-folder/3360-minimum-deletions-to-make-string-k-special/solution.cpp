class Solution {
public:
    int minimumDeletions(string word, int k) {
        int res = word.length();
        unordered_map<char, int> cnt;
        for(char c : word) {
            cnt[c]++;
        }

        for(auto &[_, a] : cnt) {
            // char with freq less than a will be deleted
            int deleted = 0;
            for(auto &[_, b] : cnt)  {
                if(b < a) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a+k);
                }
            }
            res = min(res, deleted);
        }
        return res;
    }
};
