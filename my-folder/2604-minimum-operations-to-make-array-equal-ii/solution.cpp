class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> diff;
        long long sum = 0;
        long long res = 0;

        for(int i = 0; i < n; i++) {
            if(k == 0 && nums1[i] != nums2[i]) return -1;
            else if(k != 0 && (nums1[i]-nums2[i]) % k != 0) return -1;
            diff.push_back(nums1[i]-nums2[i]);
            sum += (nums1[i]-nums2[i]);
            if((nums1[i]-nums2[i]) > 0) res += (nums1[i]-nums2[i]) / k;
        }
        if(sum != 0) return -1;
        return res;
    }
};
