class Solution {
public:
    int digitSum(int n) {
        int res = 0;
        
        while(n) {
            res +=(n%10);
            n /= 10;
        }
        
        return res;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for(int num : nums) {
            sum1+= num;
            sum2 += digitSum(num);
            
        }
        return abs(sum1-sum2);
    }
};
