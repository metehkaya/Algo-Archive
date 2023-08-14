class Solution {
public:
    int accountBalanceAfterPurchase(int x) {
        if(x%10 >= 5)
            x = 10*(x/10+1);
        else
            x = 10*(x/10);
        return 100-x;
    }
};
