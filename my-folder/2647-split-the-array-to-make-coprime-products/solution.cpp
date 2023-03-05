class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int cnt = 0;
        map<int, int> suf, pref, vis;
        for(auto i : nums){
            for(int j = 2; j <= sqrt(i); j++){
                while(i%j == 0){
                    suf[j]++;
                    i/=j;
                }
            }
            if(i>=2) suf[i]++;
        }
        int k = 0;
        for(auto i : nums){
            bool check = false;
            for(int j = 2; j <= sqrt(i); j++){
                while(i%j == 0){
                    pref[j]++;
                    suf[j]--;
                    i/=j;
                    if(suf[j] == 0 && vis[j]++ == 0) cnt++;
                }
            }
            if(i>=2) {
                pref[i]++;
                suf[i]--;
                if(suf[i] == 0 && vis[i]++ == 0) cnt++;
            }
            if(cnt == pref.size() && k<nums.size()-1) return k;
            k++;
        }
        return -1;
    }
};
