class Solution {
public:
    const int MOD = (int) 1e9+7;
    int numFactoredBinaryTrees(vector<int>& ar) {
        int n = ar.size();
        map<int,int> mp;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]] = i;
        int ans = 0;
        vector<int> dp;
        for( int i = 0 ; i < n ; i++ ) {
            int res = 1;
            for( int j = 0 ; j < i && ar[j] <= ar[i]/ar[j] ; j++ )
                if(ar[i] % ar[j] == 0) {
                    map<int,int>::iterator mit = mp.find(ar[i]/ar[j]);
                    if(mit != mp.end()) {
                        int idx = mit->second;
                        long long add = (idx == j) ? 1 : 2;
                        add = add * dp[j] * dp[idx] % MOD;
                        res = (res+add) % MOD;
                    }
                }
            dp.push_back(res);
            ans = (ans + res) % MOD;
        }
        return ans;
    }
};