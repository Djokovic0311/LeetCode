class Solution {
public:
    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        long res = 0, j = 0, jmin = -1, jmax = -1, n = arr.size();
        for (int i = 0; i < n; ++i) {
            if  (arr[i] < minK || arr[i] > maxK) {
                jmin = jmax = -1;
                j = i + 1;
            }
            if (arr[i] == minK) jmin = i;
            if (arr[i] == maxK) jmax = i;
            res += max(0L, min(jmin, jmax) - j + 1);
        }
        return res;     
    }
};
