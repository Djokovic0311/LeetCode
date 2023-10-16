class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n = slots1.size(), m = slots2.size();
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int p1 = 0, p2 = 0;
        while(p1 < n && p2 < m) {
            int l = max(slots1[p1][0], slots2[p2][0]);
            int r = min(slots1[p1][1], slots2[p2][1]);
            if(r - l >= duration) 
                return {l,l+duration};
            if(slots1[p1][1] < slots2[p2][1])
                p1++;
            else p2++;
        }
        return {};
    }
};
