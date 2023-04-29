typedef long long LL;

class Solution {
public:
    const LL base = 31;
    const LL mod = (int) 1e9+7;
    const static int maxl = 301;
    const static int maxn = 5000;
    LL pref[maxn];
    LL suff[maxn];
    LL powr[maxl];
    int char2int(char c) {
        return c-'a'+1;
    }
    void add(vector<vector<int>>& ans , int i , int j) {
        vector<int> v;
        v.push_back(i);
        v.push_back(j);
        ans.push_back(v);
    }
    vector<vector<int>> palindromePairs(vector<string>& ar) {
        int n = ar.size();
        powr[0] = 1;
        for( int i = 1 ; i < maxl ; i++ )
            powr[i] = (powr[i-1] * base) % mod;
        for( int i = 0 ; i < n ; i++ ) {
            int len = ar[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                pref[i] = (base*pref[i]+char2int(ar[i][j]))%mod;
                suff[i] = (base*suff[i]+char2int(ar[i][len-1-j]))%mod;
            }
        }
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(i != j) {
                    int l1 = ar[i].length();
                    int l2 = ar[j].length();
                    LL val1 = (powr[l2]*pref[i]+pref[j])%mod;
                    LL val2 = (powr[l1]*suff[j]+suff[i])%mod;
                    if(val1 == val2)
                        add(ans,i,j);
                }
        return ans;
    }
};