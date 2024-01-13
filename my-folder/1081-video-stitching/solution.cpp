class Solution {
public:
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        int res = 0;
        int i = 0, s = 0, e = 0;
        while(s < time) {
            while(i < n && clips[i][0] <= s) {
                e = max(e, clips[i][1]);
                i++;
            }
            if(s == e) return -1;
            s = e;
            res++;
        }
        return res;
    }
};
