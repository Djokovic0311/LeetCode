class Solution {
public:
    bool isPalindrome(int n){
        string s=to_string(n);
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int dec(int x){
        while(!isPalindrome(x)){
            x++;
        }
        return x;
    }
    int inc(int x){
        while(!isPalindrome(x)){
            x--;
        }
        return x;
    }
    long long val(int a,vector<int> nums){
        long long ans=0;
        for(int i:nums){
            ans+=abs(i-a);
        }
        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        
        int a=inc(nums[n/2]);
        int b=dec(nums[n/2]);
        
        return min(val(a,nums),val(b,nums));
        
    }
};