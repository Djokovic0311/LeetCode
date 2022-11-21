class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        vector<int> res;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(nums[mid] == target) {
                int tmp = mid;
                while(tmp >= 0 && nums[tmp] == target) tmp--;
                while(mid < nums.size() && nums[mid] == target) mid++;
                res.push_back(tmp+1);
                res.push_back(mid-1);
                break;                
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        if(res.empty()) {
            return {-1, -1};
        }
        return res;
    }
};