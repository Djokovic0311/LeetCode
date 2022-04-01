class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        string ans;
		
        if(n==1) return ans=to_string(nums[0]);
        if(n==2) return ans=to_string(nums[0])+"/"+to_string(nums[1]);

        ans=to_string(nums[0]);
        ans.append("/(");
        for(int i=1;i<n-1;i++){
            ans.append(to_string(nums[i])+"/");
        }
        ans.append(to_string(nums[n-1]));
        ans.append(")");
		
		// finally this becomes as a/(b/c/d/....) which is our answer
		
        return ans;        
    }
};