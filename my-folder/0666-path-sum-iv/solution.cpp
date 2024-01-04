class Solution {
public:
    int pathSum(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> mp0, mp1;
        int last = 1;
        /*
        Input: nums = [113,215,221]
        Output: 12
        113: mp1[1] = 3
        215: mp0[1] = 3 last = 2, mp1[1] = 3+5 = 8
        221: mp1[2] = 3+1 = 4
        res = 4+8 = 12
        */
        for(auto num : nums) {
            int x = num / 100, y = num%100/10, z = num % 10;
            if(x > last) {
                // check previous layer, if the node has been added to current layer
                for(auto& [a,b] : mp0) {
                    if(mp1.count(a*2) || mp1.count(a*2-1)) continue;
                    res += b;
                }
                mp0.clear();
                swap(mp1, mp0);
                last = x;
            }
            mp1[y] = mp0[(y+1)/2] + z;
        }

        for(auto& [a,b] : mp0) {
            if(mp1.count(a*2) || mp1.count(a*2-1)) continue;
            res += b;
        }

        for(auto&[a,b] : mp1) {
            res+=b;
        }
        return res;
    }
};
