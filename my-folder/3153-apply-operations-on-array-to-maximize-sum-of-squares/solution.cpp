const int mod = 1e9 + 7;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> bits(32);
        for (int i = 0 ; i < n ; i++) {
            int x =nums[i];
            for (int j = 0 ; j < 32 ; j++) {
                if (x & (1 << j)) {
                    bits[j]++;
                }
            }
        }
        vector<long long> ans;
        long long cnt = 0 ;
        for (int i = 0 ; i < n ; i++) {
            long long num = 0;
            for (int j = 0 ; j < 32 ; j++) {
                if (bits[j]) {
                    num |= (1 << j);
                    bits[j]--;
                }
            }
            ans .push_back(1ll*num * num);
        }
        sort(ans.rbegin(),ans.rend());
        for(int i = 0 ; i<k ; i++)
            cnt=(cnt%mod+(ans[i]%mod))%mod;
        return cnt ;

    
    }
};
