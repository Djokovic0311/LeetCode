class Solution {
public:
    string convertToBase7(int num) {
        string res;
        int tmp = num;
        num = abs(num);
        while(num >= 7) {
            res += to_string(num%7);
            num /= 7;
        }
        
        res += to_string(num);
        if(tmp<0) res+='-';
        reverse(res.begin(), res.end());
        return res;
    }
};