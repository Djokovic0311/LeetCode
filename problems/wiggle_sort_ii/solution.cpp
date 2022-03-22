class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> temp(n);
        int i = 1, j = n-1;
        while(i <nums.size()){
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        i = 0;
        while(i<nums.size()){
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        for(int it =0; it<n;it++){
            nums[it] = temp[it];
        }        
    }
};