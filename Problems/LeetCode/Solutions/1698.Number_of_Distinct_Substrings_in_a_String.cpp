class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int countDistinct(string s) {
        int n = s.length();
        unordered_set<int> vals[n];
        vector<int> mp;
        for( int i = 0 ; i < 26 ; i++ )
            mp.push_back(i);
        random_shuffle(mp.begin(),mp.end());
        for( int i = 0 ; i < n ; i++ ) {
            int val = 0;
            for( int j = i ; j < n ; j++ ) {
                val = ( 26LL*val + mp[s[j]-'a'] ) % MOD;
                vals[j-i].insert(val);
            }
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += vals[i].size();
        return ans;
    }
};