class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        multiset<int> s[n+1];
        s[0].insert(0);
        multiset<int> curr({0});
        for( int i = 1 ; i <= n ; i++ ) {
            int p = prices[i-1];
            int cost = (*curr.begin()) + p;
            curr.insert(cost);
            if(2*i <= n)
                s[2*i].insert(cost);
            for(int val : s[i-1]) {
                auto it = curr.find(val);
                curr.erase(it);
            }
        }
        return *curr.begin();
    }
};
