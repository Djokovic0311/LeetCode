class Solution {
public:
    int helper(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> dp1(n,0), dp2(n,0);
        int sum = 0;
        for(int i = 0; i <n; i++) {
            if(i < firstLen) {
                sum += nums[i];
                dp1[i] = sum;
            }
            else {
                sum = sum + nums[i] - nums[i-firstLen];
                dp1[i] = max(dp1[i-1],sum);
            }
        }
        sum = 0;
        for(int i = n-1; i>= 0; i--) {
            if(i + secondLen > n-1) {
                sum += nums[i];
                dp2[i] = sum;
            }
            else {
                sum = sum + nums[i] - nums[i+secondLen];
                dp2[i] = max(dp2[i+1],sum);
            }
        }
        int ans=0;
        //our ans window will be from x-1 to n-y
        for(int i=firstLen-1;i<n-secondLen;i++){
            ans=max(ans,dp1[i]+dp2[i+1]);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen){
        return max(helper(nums, firstLen, secondLen),helper(nums, secondLen, firstLen));
    }
};