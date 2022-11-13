class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 2;
        int res = 0;
        if(n==1)return f1;
        if(n==2)return f2;
        for(int i = 3 ; i <= n; i++) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;        
    }
};