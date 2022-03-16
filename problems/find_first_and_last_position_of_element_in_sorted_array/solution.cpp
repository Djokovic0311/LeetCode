class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid;
        vector<int> res;
        while(start <= end) {
            mid = start + (end-start) / 2;
            if(nums[mid] == target) {
                int tmp = mid;
                while(tmp >= 0 && nums[tmp] == target) tmp--;
                while(mid < nums.size() && nums[mid] == target) mid++;
                res.push_back(tmp+1);
                res.push_back(mid-1);
                break;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        if(res.empty()) {res.push_back(-1); res.push_back(-1);}
        return res;
    }
};