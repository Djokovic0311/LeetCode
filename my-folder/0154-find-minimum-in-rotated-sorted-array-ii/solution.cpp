class Solution {
public:
    int findMin(vector<int>& nums) {
                 int start=0,end=nums.size()-1;
         while(start<end){
             int mid=(start+end)/2; //finding the mid.
             if(nums[mid]<nums[end])
                 end=mid;                //if value at mid is smaller than than the value at end.
             else if(nums[mid]>nums[end])
                 start=mid+1;         //if value at mid is larger than than the value at end.
             else
                 end--;                 // consider the test case [3,3,1,3] as mid is equal to end.
         }
         return nums[end];
    }
};
