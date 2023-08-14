typedef long long LL;

class Solution {
public:
    const LL mod = 1e9+7;
    int longestValidSubstring(string word, vector<string>& forbidden) {
        set<LL> s;
        for(string& f : forbidden) {
            LL val = 0;
            for(char c : f)
                val = (27*val + c-'a'+1) % mod;
            s.insert(val);
        }
        int n = word.length() , ans = 0;
        vector<int> v(n,n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            LL val = 0;
            for( int k = 0 ; k < 10 && i+k < n ; k++ ) {
                val = (27*val + word[i+k]-'a'+1) % mod;
                if(s.count(val))
                    v[i] = min(v[i],i+k);
            }
            if(i+1 < n)
                v[i] = min(v[i],v[i+1]);
            ans = max(ans,v[i]-i);
        }
        return ans;
    }
};
