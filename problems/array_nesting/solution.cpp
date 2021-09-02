class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[i] = nums[i];
        }
        int j = 0;
        int sum = INT_MIN;
        while(j < n){
            int tmp = 0;
            int start = j;
            while(mp[start] != -1){
                int k = start;
                start = mp[start];
                tmp ++;
                mp[k] = -1;
            }
            sum = max(sum, tmp);
            j++;
        }
        return sum;
    }
};