class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        
        
        vector<vector<long long>> ls(n + 1, vector<long long>(n + 1, 0));  // ls[i][j]= num of elements smaller than nums[i] on the left side till index j where j belongs to 0..i-1 
        vector<vector<long long>> rs(n + 1, vector<long long>(n + 1, 0)); // rs[i][j]= num of elements greater than nums[i] on the right side  till index j where j belongs to n,n-1....i+1 
        
         
        for (int j = 1; j < n; j++) { 
             // i from 0 to j-1 
           for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    ls[j][i] += 1;
                }
            }
       }
        for (int i = 0; i < n - 1; i++){
            for (int j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    rs[i][j]++;
                }
            }
        }
        
        // prefix sum
       for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (j == 0)
                continue;
            ls[i][j] += ls[i][j - 1];
        }
    }
        
    // prefix sums
    for (int i = 0; i < n - 1; i++) {
      for (int j = n - 1; j > i; j--) {
            rs[i][j] += rs[i][j + 1];
        }
    }
    for (int j = 1; j < n - 1; j++){
        for (int k = j + 1; k < n - 1; k++) {
             if (nums[j] > nums[k]){
                // num of elements smaller than nums[k] but from [0...j-1 index] and Number of elements greater than nums[j] in [k+1...n]
                ans += ls[k][j - 1] * rs[j][k + 1];
            }
        }
    }
        return ans;
    }
};
