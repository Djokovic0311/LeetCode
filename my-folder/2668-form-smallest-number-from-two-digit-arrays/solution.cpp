class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> digits;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;

        set_intersection(nums1.begin(), nums1.end(),nums2.begin(), nums2.end(),back_inserter(result));
        if(result.size() != 0) {
            sort(result.begin(), result.end());
            return result[0];
        }
        
        int smallest = nums1[0] > nums2[0] ? nums2[0]*10+nums1[0] :nums1[0]*10+nums2[0] ;
        
        return smallest;
        
    }
};
