class Solution {
public:
    bool vis[16];
    bool canMakeSquare(vector < int > & matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 0)
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        for (int i = idx; i < size(matchsticks); i++) {
            if (!vis[i]) {
                if (currentSum + matchsticks[i] <= oneSideLength) {
                    vis[i] = true;
                    if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }
    bool makesquare(vector<int>& M) {
        memset(vis, false, sizeof(vis));
        int n = M.size();
        int sum = 0;
        map<int, int> mp;
        for(auto m : M) sum += m, mp[m]++;
        if(sum % 4 != 0) return false;
        int e = sum / 4;
        return canMakeSquare(M, 0, e, 4);
    }
};
