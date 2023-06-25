typedef long long ll;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        ll nn1 = (ll) num1;
        ll nn2 = (ll) num2;
        
        for (ll i = 1; i <= 500; i++) {
            ll nr = nn1 - (nn2*i);
            
            if (nr < 0) {
                break;
            }
            
            ll cnt = 0;
            for (ll j = 0; j <= 60; j++) {
                if (nr & (1LL << j)) {
                    cnt++;
                }
            }
            
            if (cnt <= i && i <= nr) {
                return i;
            }
        }
        
        return -1;
    }
};
