class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)
                break;
            if (i > 0 and nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0) {
                    l++;
                }
                else if(sum > 0)
                    r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int last_left = nums[l], last_right = nums[r];
                while (l < r && nums[l] == last_left) ++l;
				while (l < r && nums[r] == last_right) --r;
                }
            }
        }
        return res;
    }
};
