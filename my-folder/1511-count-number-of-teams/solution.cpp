class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for(int i = 1; i < n-1; i++) {
            int left[2] = {0}, right[2] = {0};
            for(int j = 0; j < i; j++) {
                left[rating[j] < rating[i]]++;
            }
            for(int k = i+1; k < n; k++) {
                right[rating[k] < rating[i]]++;
            }

            res += left[0]*right[1] + left[1] * right[0];
        }

        return res;
    }
};
