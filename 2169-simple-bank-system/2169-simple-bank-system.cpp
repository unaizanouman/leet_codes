class Bank {
private:
    vector<long long> balance;
    int n;
    
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
        this->n = balance.size();
    }
    
    bool isValid(int account) {
        return account >= 1 && account <= n;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) return false;
        if (balance[account1 - 1] < money) return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};
