class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int flag = 0;
        if(x < 0) flag = -1;
        int num = abs(x);
        while(num > 0){
            int tmp = num % 10;
            num /= 10;
            if(result * 10 + tmp> INT_MAX) 
                return 0;
            result = result * 10 + tmp;
        }
        return flag == 0 ? result : -result;
    }
};
