
class Solution {
public:
    
    int bs(vector<int> array, double target, vector<bool>& marked) {
        int left = 0, right = array.size()-1;
        while(left <= right) {
            int mid = (left + right)/2;
            // cout << array[mid] <<endl;
            if(array[mid] < target)
                left = mid + 1;
            else
               right = mid - 1;
        }
        // cout << "left " << target << endl;
        while(marked[left]) left++;
        return left;


}

    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, lo = 0, hi = n/2;
        while(lo < n/2 && hi < n) {
            if(nums[lo] * 2 <= nums[hi]) ans += 2, lo++, hi++;
            else hi++;
        }
        return ans;      
    }
};
