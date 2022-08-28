class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), m = travel.size();
        int res = 0;
        vector<int> last(3,-1);
        for(int i = 0; i < n; i++) {
            if(garbage[i].find('M')!=-1)
                last[0] = i;
            if(garbage[i].find('P')!=-1)
                last[1] = i;
            if(garbage[i].find('G')!=-1)
                last[2] = i;
            res += garbage[i].length();
        }
        for(int a : last) {
            for(int j = 0; j < a; j++) {
                res += travel[j];
            }
        }
        return res;
    }
};
