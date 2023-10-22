class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int, int> m;
        for (int x : nums) m[x]++;
        vector<int> b;
        for (auto &it : m) b.push_back(it.second);
        sort(b.begin(), b.end());
        int ans = nums.size();
        for (int i = b[0]; i >= 1; --i) {
            bool ok = true;
            int t = 0;
            for (int x : b) {
                const int aa = x / i;
                const int bb = x % i;
                if (bb > aa) {
                    ok = false;
                    break;
                }
                const int yy = (aa - bb) / (i + 1);
                t += aa - yy;
            }
            if (ok) ans = min(ans, t);
        }
        return ans;
    }


};

