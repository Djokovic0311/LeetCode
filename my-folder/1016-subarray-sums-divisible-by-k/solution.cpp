class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
                int pref = 0; 
        vector<int> cPref(k); 
        cPref[pref]++;
        int n = nums.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            pref = (pref + nums[i]) % k;
            if(pref < 0) pref += k; 
            ans += cPref[pref];
            cPref[pref]++;
        }
        return ans;
    }
};
