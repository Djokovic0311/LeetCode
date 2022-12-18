class Solution {
public:
    int helper(int num) {
        int res = 0;
    for (int i = 2; i <= num; i++)  //循环查找判断质因数
    {
        while (num % i == 0)    //若i为num的质因数，则输出i
        {
            res += i;
            num /= i;    
        }
        
    }
        return res;
    }
    int smallestValue(int n) {
        while(helper(n) < n) {
            n = helper(n);
        }
        
        return n;
    }
};
