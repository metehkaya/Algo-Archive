class Solution {
public:
    long long maxScore(vector<int>& prices) {
        int n = prices.size();
        map<int,long long> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[i-prices[i]] += prices[i];
        long long ans = 0;
        for(auto it : mp)
            ans = max(ans,it.second);
        return ans;
    }
};
