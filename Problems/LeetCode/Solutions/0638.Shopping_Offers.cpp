class Solution {
public:
    int n,m;
    map<int,map<vector<int>,int>> dp;
    vector<int> price,needs;
    vector<vector<int>> special;
    int f(int idx) {
        if(idx == m) {
            int cost = 0;
            for( int i = 0 ; i < n ; i++ )
                cost += price[i]*needs[i];
            return cost;
        }
        if(dp.find(idx) != dp.end() and dp[idx].find(needs) != dp[idx].end())
            return dp[idx][needs];
        int ans = f(idx+1);
        for( int i = 0 ; i < n ; i++ )
            needs[i] -= special[idx][i];
        if(*min_element(needs.begin(),needs.end()) >= 0)
            ans = min(ans,f(idx)+special[idx][n]);
        for( int i = 0 ; i < n ; i++ )
            needs[i] += special[idx][i];
        return dp[idx][needs] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size() , m = special.size();
        this->price = price;
        this->needs = needs;
        this->special = special;
        return f(0);
    }
};
