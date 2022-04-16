class ATM {
public:
    ATM() {
        bank = {0,0,0,0,0};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++) {
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5,0);
        vector<long long> ck = bank;
        for(int i = 4; i >= 0; i--) {
            // cout << bank[i] << ' ';
            if(bank[i] == 0) continue;
            // cout << amount <<  ' ';
            long long cur_need = amount / record[i];
            cur_need = min(bank[i], cur_need);
            // cout << record[i] <<' ' << cur_need<<endl;
            amount -= cur_need * record[i];
            bank[i] -= cur_need;
            res[i] = cur_need;
            // cout << res[i] <<  ' ';
            // cout <<endl;
        }
        // for(int i = 0; i < 5;i++) cout << res[i] <<' ';
        // cout << amount<<endl;
        // cout << endl;
        if(amount == 0)
            return res;
        else {
            bank = ck;
            return {-1};
        }
    }
private:
    vector<long long> bank;
    vector<int> record = {20,50,100,200,500};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
