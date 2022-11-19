class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pretemp=0, sum=0;
        map<int,int> mods;
        for (int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;
            if (mods[sum]) return true;
            mods[pretemp] ++;
            pretemp = sum;
        }
        return false;        
    }
};
