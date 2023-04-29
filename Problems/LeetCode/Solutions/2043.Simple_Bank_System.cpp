class Bank {
public:
    int n;
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        this->n = balance.size();
        this->balance = balance;
    }
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(account1 < n && account2 < n && balance[account1] >= money) {
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        }
        return false;
    }
    bool deposit(int account, long long money) {
        account--;
        if(account < n) {
            balance[account] += money;
            return true;
        }
        return false;
    }
    bool withdraw(int account, long long money) {
        account--;
        if(account < n && balance[account] >= money) {
            balance[account] -= money;
            return true;
        }
        return false;
    }
};
