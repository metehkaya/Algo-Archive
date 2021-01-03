class Solution {
public:
    const int mod = (int)1e9+7;
    int countPairs(vector<int>& ar) {
        map<int,int> cnt;
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            for( int k = 1 ; k <= (1<<21) ; k <<= 1 ) {
                int x = k-ar[i];
                auto it = cnt.find(x);
                if(it != cnt.end())
                    ans = (ans + it->second) % mod;
            }
            cnt[ar[i]]++;
        }
        return ans;
    }
};