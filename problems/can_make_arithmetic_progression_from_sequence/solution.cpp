class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int dif = arr[1]-arr[0];
        if(n==2) return true;
        for(int i = 2; i < n; i++) {
            if(arr[i]-arr[i-1] != dif) return false;
        }
        return true;
    }
};