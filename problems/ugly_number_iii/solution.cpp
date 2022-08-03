typedef long long ll;
class Solution {
public:
    ll lcm(ll a, ll b) {
        return a*b / __gcd(a, b);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        ll N = (ll)n, A = ll(a), B = ll(b), C = ll(c);
        ll lo = 1, hi = 2000000000, mid, ans;
        
        while(lo <= hi)
        {
            mid = lo + (hi - lo)/2;
            ll cnt = 0;
            cnt += mid/A;
            cnt += mid/B;
            cnt += mid/C;
            cnt -= mid / lcm(A, B);
            cnt -= mid / lcm(B, C);
            cnt -= mid / lcm(C, A);
            cnt += mid / lcm(a, lcm(b, c));
            
            if(cnt >= N)
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};

