class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& v) {
        int n = v.size() , ans = 1 , mx = -1;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[v[i]] = i;
        for( int i = 0 ; i < n ; i++ ) {
            mx = max(mx,mp[v[i]]);
            if(i == mx and i != n-1)
                ans = (ans*2) % mod;
        }
        return ans;
    }
};
