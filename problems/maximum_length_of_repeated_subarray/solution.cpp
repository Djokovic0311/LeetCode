class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), lcs = 0;
        
        vector<int> prev(n+1, 0);
        
        for(int i = 1; i <= m; i++){
            vector<int> curr(n+1, 0);
            for(int j = 1; j <= n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    lcs = max(curr[j], lcs);
                }
            }
            prev = curr;
        }
        return lcs;        
    }
};