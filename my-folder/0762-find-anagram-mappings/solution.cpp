class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans = nums1;
    
    map<int,int> mp;
    
    for(int i=0; i<nums2.size(); i++){
        mp[nums2[i]] = i;
    }
    
    for(int i=0; i<nums1.size(); i++){
            ans[i] = mp[nums1[i]];
    }
    return ans;        
    }
};
