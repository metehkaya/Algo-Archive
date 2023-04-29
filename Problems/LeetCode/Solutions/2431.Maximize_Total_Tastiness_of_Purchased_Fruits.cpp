class Solution {
public:
    int dp[100][1001][6];
    vector<int> price, tastiness;
    int f(int id , int amount , int coupon) {
        if(id == -1)
            return 0;
        int& ans = dp[id][amount][coupon];
        if(ans != -1)
            return ans;
        ans = f(id-1,amount,coupon);
        if(amount >= price[id])
            ans = max(ans,f(id-1,amount-price[id],coupon)+tastiness[id]);
        if(coupon > 0 and amount >= price[id]/2)
            ans = max(ans,f(id-1,amount-price[id]/2,coupon-1)+tastiness[id]);
        return ans;
    }
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        this->price = price;
        this->tastiness = tastiness;
        int n = price.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,maxAmount,maxCoupons);
    }
};
