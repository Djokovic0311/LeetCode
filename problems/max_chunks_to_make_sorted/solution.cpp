class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = -1;
        int res = 0;
        int n = arr.size();
        for(int i = 0; i <= n; i++) {
            if(i == n) return res;
            mx = max(mx, arr[i]);
            if(mx == i) res++;
        }
        return -1;
    }
};