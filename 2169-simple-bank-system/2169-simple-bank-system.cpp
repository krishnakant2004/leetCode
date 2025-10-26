class Bank {
public:
    vector<long long> bank;
    Bank(vector<long long>& balance) {
        int n = balance.size();

        bank.resize(n,0);
        for(int i = 0;i<n;i++) bank[i] = balance[i];
    }
    
    bool transfer(int a1, int a2, long long money) {
        int size = bank.size();

        if(a1 <= 0 || a1 > size || a2 < 0 || a2 > size) return false;
        if(bank[a1-1] >= money){
            bank[a1-1] -= money;
            bank[a2-1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int a1, long long money) {
        int size = bank.size();
        if(a1 <= 0 || a1 > size) return false;
        bank[a1-1] += money;
        return true;
    }
    
    bool withdraw(int a1, long long money) {
        int size = bank.size();
        if(a1 <= 0 || a1 > size || bank[a1-1] < money) return false;
        bank[a1-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */