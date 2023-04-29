class Solution {
public:
    const int mod = (int) 1e9+7;
    int countDistinctStrings(string s, int k) {
        int n = s.length() , ans = 1;
        for( int i = 0 ; i < n-k+1 ; i++ )
            ans = 2*ans%mod;
        return ans;
    }
};
