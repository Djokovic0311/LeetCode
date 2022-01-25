class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int start = 1;
        while(start < n) {
            if(arr[start-1] < arr[start]) start++;
            else break;
        }
        if(start == n || start == 1) return false;
        while(start < n) {
            if(arr[start-1] > arr[start]) start++;
            else break;
        }
        if(start == n) return true;
        else return false;
    }
};
