class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        // sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                for(int k = j + 1; k < n - 1; k++){
                    for(int p = k + 1; p < n; p++)
                        if(nums[i] + nums[j] + nums[k] == nums[p]){
                            count ++;
                            cout << i << ' ' << j << ' ' << k << endl;
                            // break;
                        }
                }
            }
        }
        return count;
    }
};
