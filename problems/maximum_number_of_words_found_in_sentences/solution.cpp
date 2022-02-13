class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            stringstream ss(sentences[i]);
            string tmp;
            int res = 0;
            while(ss>> tmp) {
                res++;
            }
            mx = max(mx,res);
        }
        return mx;
    }
};