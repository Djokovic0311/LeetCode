class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0;
        int n = gain.size();
        int tmp = 0;
        for(int i = 0 ; i< n; i++) {
            tmp += gain[i];
            high = max(high, tmp);
        }
        return high;
    }
};