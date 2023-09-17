class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(nums[0] == n || nums[n-1] == 0) return 1;
        
        int ways = 1, counter = 0;
        int left = -1, right = n;
        for(int i = 0; i < n; ++i) {
            
            //i以及以后都没被选
            if(((i > 0 && i > nums[i-1]) && i < nums[i]) || (i == 0 && 0 < nums[i])) counter++;
            // else if(i < nums[i]) counter++;
            // cout << i << " " << nums[i] << " " << counter << endl;
        }
        if(n > nums[n-1]) counter++;
        return counter;     
    }
};
