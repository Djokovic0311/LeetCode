class Solution {
public:
    long long f(const vector<int>& arr, int target, int k) {
        long long n=arr.size(),ans=0,cnt=0,left=0;
        for (long long right=0;right<n;right++){
            if (arr[right] == target)cnt++;
            while(cnt>=k){
                ans+=(n-right);
                if(arr[left]==target) cnt--;
                left++;
            }
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        return f(nums,maxi,k);
    }
};