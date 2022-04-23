class Solution {
public:
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        int res = 0;
        for(int i = 0, s = 0, e = 0; s < time; s = e, res++) {
            for(;i < n && clips[i][0] <= s;i++) {
                e = max(e, clips[i][1]);
            }
            if(s==e) return -1;
        }
        return res;
    }
};
