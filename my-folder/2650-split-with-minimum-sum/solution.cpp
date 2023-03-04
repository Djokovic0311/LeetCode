class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        int n = s.length();
        int num1 = 0, num2 = 0;
        sort(s.begin(), s.end());
        
        for(int i = 0; i < n; i++) {
            num1 = num1 * 10 + s[i]-'0';
            i++;
            if(i < n){
                num2 = num2 * 10 + s[i]-'0';
                
            }
            else break;
            
        }
        // cout << num1 << " " << num2;
        return num1 + num2;
    }
};
