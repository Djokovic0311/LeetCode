class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        sort(nums1.begin(), nums1.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        
        while(i < n1 && j < n2) {
            int idx1 = nums1[i][0], idx2 = nums2[j][0];
            int val1 = nums1[i][1], val2 = nums2[j][1];
            
            if(idx1 == idx2) {
                i++, j++;
                res.push_back({idx1, val1+val2});
            }
            else if(idx1 < idx2) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1) res.push_back(nums1[i++]);
        while(j < n2) res.push_back(nums2[j++]);
        return res;
    }
};
