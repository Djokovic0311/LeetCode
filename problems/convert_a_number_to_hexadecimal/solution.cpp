class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        unsigned int num1 = num;
        string hex = "";
        int base = 16;
        int rem;
        while(num1 > 0){
            rem = num1 % base;
            if(rem < 10){
                hex += ('0' + (rem));
            }else{
                hex += ('a' + (rem%10));
            }
            num1 = num1 / base;
        }
        reverse(hex.begin(), hex.end()); 
		
        return hex;        
    }
};