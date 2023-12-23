class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        long long res=0;
        
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0]=(long long)nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + (long long)nums[i];
        }
        
        for(int i = 2; i < n; i++) {
            // cout << prefix[i] << " ";
            if(nums[i] < prefix[i-1]) {
                res = prefix[i];
            }
        }
        // cout << endl;
        
        return res == 0 ?-1 : res;
    }
};
