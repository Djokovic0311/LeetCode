class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int max1 = arr[0] , max0 = arr[0] , ans = arr[0];
		for(int i=1;i<arr.size();i++){
            max1 = max(max1+arr[i] , max(arr[i] , max0) );
            max0 = max(max0+arr[i] , arr[i]);
            ans = max(ans,max1);
        }
        return ans;        
    }
};