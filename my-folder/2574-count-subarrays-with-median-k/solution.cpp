class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int target=0, res=1;
        unordered_map<int,int> record;

        // k itself
        record[0]=1;
        
        // find position of k in nums
        for (; target<nums.size(); ++target)
            if (nums[target]==k) break;
        
        // left side
        for (int i=target-1, cur=0; i>=0; --i) {
            if (nums[i]>k) ++cur;
            else --cur;
            
            ++record[cur];
            if (cur==0 || cur==1) ++res;
        }
        
        // right side
        for (int i=target+1, cur=0; i<nums.size(); ++i) {
            if (nums[i]>k) ++cur;
            else --cur;

            res+=record[-cur]+record[-cur+1]; 
        }
        
        return res;
    }
};
