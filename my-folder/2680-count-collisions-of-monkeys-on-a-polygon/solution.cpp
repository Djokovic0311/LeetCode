class Solution {
public:
    int monkeyMove(int n) {
        int mod = 1e9+7;
        long long res = 1;
        if(n <= 100000000) {
            while(n) {
                res = (res << 1) % mod;
                n--;
            }            
        } else {
            int a = n / 10000000, b = n % 10000000;
            int i = 0;
            long long tmp = 1;
            while(i < 10000000) {
                tmp = (tmp << 1) % mod;
                i++;
            }  
            // cout << a << ' ' << b;
            while(a) {
                res = (res * tmp) % mod;
                a--;
            }
            while(b) {
                res = (res << 1) % mod;
                b--;
            }  
            
        }

        // cout << res << endl;
        return int(res-2) >= 0 ? int(res-2) : res-2+mod;
    }
};
