class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<int, long> m;
        m[1] = 1;
        int curDay = 1, ans = 0;
        queue<int> doubtfulBird;
        for (int i = 0; i < forget; ++i) doubtfulBird.push(0);
        while (curDay <= n){
            ans += m[curDay];
            ans -= doubtfulBird.front();
            doubtfulBird.pop();
            doubtfulBird.push(m[curDay] % 1000000007);
            int singingBird = m[curDay];
            for (int i = curDay + delay; i < curDay + forget; ++i){
                m[i] += singingBird;
                m[i] %= 1000000007;
            }
            ans %= 1000000007;
            ++curDay;
        }
        return ans < 0 ? ans + 1000000007 : ans;        
    }
};
