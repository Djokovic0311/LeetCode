class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> left;
        for(int i = 0; i < n; i++) {
            left.push_back(capacity[i] - rocks[i]);
        }
        sort(left.begin(),left.end());
        int i = 0;
        while(i < n && left[i] == 0) i++;
        if(i==n) return n;
        for(; i < n; i++) {
            if(additionalRocks - left[i] >= 0)
                additionalRocks -= left[i];
            else break;
        }
        return i;
    }
};
