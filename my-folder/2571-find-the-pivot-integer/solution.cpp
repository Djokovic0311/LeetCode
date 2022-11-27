class Solution {
public:
    int pivotInteger(int n) {
        int res = 1;
        int total = (n+1) * n / 2;
        int cur = 0;
        int behind;
        for(int i = 1; i <= n; i++) {
            cur += i;
            behind = total - cur + i;
            if(cur == behind) return i;
        }
        return -1;
    }
};
