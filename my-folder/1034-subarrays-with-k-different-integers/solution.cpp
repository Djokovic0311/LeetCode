class Solution { 
public:
    int fun(int k,vector<int> nums) {
        int res = 0;
        int i = 0, j = 0;
        int n = nums.size();
        vector<int> freq(n+1,0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 0) count++;
            freq[nums[i]]++;
            if(count <= k) {
                res += (i-j+1);
            }
            else {
                while(count > k){
                    freq[nums[j]]--;
                    if(freq[nums[j]]== 0) {
                        count--;
                    }
                    j++;
                }
                res += (i-j+1);
            }

        }    
        return res;    
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(k, nums) - fun(k-1,nums);
    }
};
