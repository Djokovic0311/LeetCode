class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int forward = 0;
        for(int i = n;  i >= 0; i--){
            forward += digits[i];
            if(i == n){
                forward++;
            }

            digits[i] = forward % 10;
            forward /= 10;
        }
        if(forward != 0) digits.insert(digits.begin(), forward);
        return digits;        
    }
};