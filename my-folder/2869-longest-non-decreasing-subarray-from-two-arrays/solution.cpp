class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int res=1;
        vector<int> vec1(n,1),vec2(n,1);
        for(int i=1;i<n;i++){
            if(nums1[i]>=nums1[i-1]) vec1[i]=vec1[i-1]+1;
            if(nums2[i]>=nums2[i-1]) vec2[i]=vec2[i-1]+1;
            if(nums1[i]>=nums2[i-1]) vec1[i]=max(vec1[i],vec2[i-1]+1);
            if(nums2[i]>=nums1[i-1]) vec2[i]=max(vec2[i],vec1[i-1]+1);
            res=max(res,max(vec1[i],vec2[i]));
        }
        return res;   
    }
};
