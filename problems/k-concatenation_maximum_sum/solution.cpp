class Solution {
public:
    long long N=1000000007;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        int  ans=0;
        long long sum=0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
         if(k == 1){
            ans= (kadanesForOne(arr,n))%N;
        }
        else if(sum > 0){
            ans= (kadanesForTwo(arr,n) + ((k - 2) * (sum)))%N;
        }else{
            ans= (kadanesForTwo(arr,n))%N;
        }
        if(ans<0)return 0;
        return ans%N;
    }
     int kadanesForOne(vector<int> arr, int n) {
        int finalans = arr[0];
        int curr = arr[0];
        for(int i = 1 ; i < n; i++){
            curr = max(arr[i], arr[i] + curr);
            finalans = max(finalans, curr);
        }
        return finalans; 
    }
    int kadanesForTwo(vector<int> arr, int n) {
        int finalans = arr[0];
        int curr = arr[0];
        for(int i = 1 ; i < 2 * n; i++){
            curr = max(arr[i % n], arr[i % n] + curr);
            finalans = max(finalans, curr);
        }
        return finalans; 
    }
};