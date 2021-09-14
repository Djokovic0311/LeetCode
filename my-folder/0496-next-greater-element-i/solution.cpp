class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> m; // to store {nums2[i], nextGreater of nums2[i]}
        stack<int> s; // the rule is to insert elements which are equal or smaller
        
        for(int i=0;i<n;++i)
        {
            while(!s.empty() and s.top()<=nums2[i])
            {
                m[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();++i)
        {
            if(m[nums1[i]]==0) nums1[i]=-1;
            else nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};
