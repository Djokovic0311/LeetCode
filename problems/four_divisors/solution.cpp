class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            int cnt=0;
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    
                if(j==nums[i]/j)
                {
                    cnt=cnt+1;
                    sum=sum+j;
                }
                else
                {
                    cnt=cnt+2;
                    sum=sum+j+nums[i]/j;
                }
                }
            }
            if(cnt==4)
            {
                ans+=sum;
            }
        }
        return ans;
    }
};