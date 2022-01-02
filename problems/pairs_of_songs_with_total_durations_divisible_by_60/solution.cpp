class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mods(60,0);
        int  ans = 0;
        for(int i = 0;i < time.size();i++){
            ans += mods[(60  - (time[i]%60)) % 60];
            mods[time[i]%60]++;
        }
        return ans;
    }
};