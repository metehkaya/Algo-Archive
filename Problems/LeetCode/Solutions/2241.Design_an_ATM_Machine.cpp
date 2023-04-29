typedef long long LL;

class ATM {
public:
    LL cnt[5] = {0,0,0,0,0};
    int vals[5] = {20,50,100,200,500};
    ATM() {
        
    }
    void deposit(vector<int> banknotesCount) {
        for( int i = 0 ; i < 5 ; i++ )
            cnt[i] += banknotesCount[i];
    }
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        for( int i = 4 ; i >= 0 ; i-- ) {
            ans[i] = min((LL)amount/vals[i],cnt[i]);
            amount -= ans[i]*vals[i];
        }
        if(amount > 0) {
            ans.clear();
            ans.push_back(-1);
        }
        else
            for( int i = 0 ; i < 5 ; i++ )
                cnt[i] -= ans[i];
        return ans;
    }
};
