class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = INT_MAX;
        int l = customers.length();
        string cus = "";
        for(int i = 0; i < l; i++){
            cus += customers[i] == 'Y' ? '1' : '0';
        }
        
        string close(l,'0');
        int tmp = 0;
        for(int i = 0; i < l; i++) {
            if(close[i] != cus[i]) tmp++;
        }
        
        penalty = tmp;
        int idx = 0;
        
        for(int i = 0; i < l; i++) {
            close[i] = '1';
            if(close[i] != cus[i]) tmp++;
            else tmp--;
            if(tmp < penalty) idx = i+1, penalty = tmp;
        }

        // cout << penalty;
        return idx;
        
    }
};
