class Solution {
public:
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int>> candidate;
    int res = 0;
    int numSquarefulPerms(vector<int>& nums) {
        for(int num : nums) {
            count[num]++;
        }
        for(auto i : count) {
            for(auto j : count) {
                int x = i.first, y = j.first;
                int s = sqrt(x+y);
                if(x+y == s * s)
                    candidate[x].insert(y);
            }
        }
        for(auto e : count) {
            dfs(e.first, nums.size()-1);
        }

        return res;

    }
    void dfs(int x, int idx) {
        count[x]--;
        if(idx == 0) {
            res++;
        }
        for(auto i : candidate[x]) {
            if(count[i] > 0) {
                dfs(i, idx-1);
            }
        }
        count[x]++;
    }
};
