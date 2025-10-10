class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> v(k, -1001);
        for(int i = 0; i < n; i++) {
            v[i % k] = max(v[i%k]+energy[i], energy[i]);
        }
        int res = INT_MIN;
        for(int i = 0; i < k; i++) {
            res = max(res, v[i]);
        }
        return res;
    }
};
