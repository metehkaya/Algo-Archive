typedef long long LL;

class Solution {
public:
    const LL base = 31;
    const LL mod = 1e9+7;
    int equalDigitFrequency(string s) {
        vector<int> digval;
        for( int i = 1 ; i < base ; i++ )
            digval.push_back(i);
        random_shuffle(digval.begin(),digval.end());
        int n = s.length() , ans = 0;
        unordered_set<LL> hash_values[n];
        for( int i = 0 ; i < n ; i++ ) {
            LL hash = 0;
            int diff = 0 , mx = 0 , len = 0;
            vector<int> cnt(10,0);
            for( int j = i ; j < n ; j++ ) {
                int c = s[j]-'0';
                if(cnt[c]++ == 0)
                    diff++;
                len++;
                mx = max(mx,cnt[c]);
                hash = (base*hash+digval[c]) % mod;
                if(len == mx*diff) {
                    auto it = hash_values[len-1].insert(hash);
                    ans += it.second;
                }
            }
        }
        return ans;
    }
};
