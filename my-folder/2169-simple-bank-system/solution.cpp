class Bank {
private:
    std::vector<long long> balances;

    // Helper function to check if account number is valid
    bool isValidAccount(int account) {
        return account >= 1 && account <= balances.size();
    }

public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        // Check if both accounts are valid and there's enough money in account1 to transfer
        if (isValidAccount(account1) && isValidAccount(account2) && balances[account1 - 1] >= money) {
            balances[account1 - 1] -= money;
            balances[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        // Check if account is valid
        if (isValidAccount(account)) {
            balances[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        // Check if account is valid and there's enough money to withdraw
        if (isValidAccount(account) && balances[account - 1] >= money) {
            balances[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
