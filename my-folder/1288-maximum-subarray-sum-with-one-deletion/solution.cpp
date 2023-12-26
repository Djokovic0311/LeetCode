class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int oneDelete = 0, noDelete = arr[0], res = arr[0];
        for(int i = 1; i < n; i++) {
            oneDelete = max(noDelete, oneDelete + arr[i]);
            noDelete = max(noDelete + arr[i], arr[i]);
            res = max(res, max(oneDelete, noDelete));
        }

        return res;
    }
};
