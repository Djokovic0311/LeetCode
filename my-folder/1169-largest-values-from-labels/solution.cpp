class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
           nums.push_back({values[i],labels[i]});
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int i=0,j=0;
        map<int,int>mp;
        int ans=0;
        while(i<numWanted && j<n)
        {
            if(mp[nums[j].second]<useLimit)
            {
                ans=ans+nums[j].first;
                mp[nums[j].second]++;
                i++;
            }
            j++;   
        }
        return ans;
    }
};
