class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long cur = mass;
        for(int i = 0; i < n; i++) {
            if(cur < asteroids[i]) return false;
            cur += asteroids[i];
        }
        return true;
    }
};
