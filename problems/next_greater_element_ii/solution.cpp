class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
		    s.push(nums[i]);
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.size()==0)
                ans.push_back(-1);
            else if(s.size()>0&&s.top()>nums[i])
                ans.push_back(s.top());
            else if(s.size()>0&&s.top()<=nums[i])
            {
                while(s.size()>0&&s.top()<=nums[i])
                    s.pop();
                if(s.size()==0)
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};