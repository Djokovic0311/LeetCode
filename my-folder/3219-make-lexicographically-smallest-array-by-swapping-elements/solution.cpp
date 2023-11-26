class Solution {
public:
    // map<int,int>par;
    int findp(int n,map<int,int>&par)
    {
        if(par[n]==n)return n;
        return par[n]=findp(par[n],par);
    }
    
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int,int>par;
        // par = vector<int>(n);
        vector<int>nums1(n);
        for(int i=0;i<n;i++)
        {
            par[nums[i]]=nums[i];
            nums1[i]=nums[i];
        }
        sort(nums1.begin(),nums1.end());
        
        map<int,multiset<int>>mp;
        mp[nums1[0]].insert(nums1[0]);
        for(int i=1;i<n;i++)
        {
            if(nums1[i]-nums1[i-1]<=limit)
            {
                int p = findp(nums1[i-1],par);
                mp[p].insert(nums1[i]);
                par[nums1[i]]=p;
            }else mp[nums1[i]].insert(nums1[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int p = findp(nums[i],par);
            auto lb = mp[p].begin();
            nums[i] = *lb;
            mp[p].erase(lb);
        }
        
        return nums;
    }
};
