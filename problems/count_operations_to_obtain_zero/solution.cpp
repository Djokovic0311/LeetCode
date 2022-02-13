class Solution {
public:
    int countOperations(int num1, int num2) {
        int times = 0;
        if(num1==0 || num2 ==0) return 0;
        while(num1 != num2) {
            if(num1 > num2) num1-= num2;
            else num2 -= num1;
            times++;
            if(num1==0||num2==0) return times;
        }
        return times+1;
    }
};