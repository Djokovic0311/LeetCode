class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n-2, false);
        vector<int> res;
        for(int num : nums){
            if(!visited[num]) {
                visited[num] = true;
            } else {
                res.push_back(num);
            }
        }
        return res;
    }
};
