class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if(n == 1) return 1;
        // int i = 0, j = 1;
//         while(i < n) {
//             if(j > n-1) {
//                 // if(nums[i] == nums[i-1]) res++;
//                 res++;
//                 return res;
//             }
//             while(j < n && nums[i] == nums[j]) {
//                 j++;
//                 res++;
//             }
//             cout << i << ' ' << j <<endl;
//             cout << res<<endl;
//             if(j == n) return res;
            
//             if(nums[i] != nums[j]) {
//                 i = j+1;
//                 j += 2;                
//             }
//         }
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1] && (i-res) % 2 == 0) res++;
        }
        return res+(n-res) % 2;
    }
};