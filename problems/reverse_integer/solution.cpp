class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int flag = 0;
        if(x < 0) flag = -1;
        int num = abs(x);
        cout<<num;
        while(num > 0){
            int tmp = num % 10;
            num /= 10;
            if(result * 10 > INT_MAX) 
                return 0;
            result = result * 10 + tmp;
            cout << num << endl;
        }
        if(flag == 0){
            return result;
        }
        else return (-1) * result;
    }
};