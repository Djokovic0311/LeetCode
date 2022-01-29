class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]>0)
                return nums[i];
            map[nums[i]]++;
        }   
        return 0; 
    }
};
