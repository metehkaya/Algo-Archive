typedef long long LL;

class Solution {
public:
    const LL BASE = 26LL;
    const LL MOD = (1LL << 32);
    int f(int len , int n , string& s) {
        unordered_map<LL,int> index;
        LL curr = 0;
        LL pBase = 1;
        for( int i = 0 ; i < len ; i++ ) {
            pBase = (pBase * BASE) % MOD;
            curr = (curr * BASE + (s[i] - 'a')) % MOD;
        }
        index[curr] = 0;
        for( int i = 1 ; i <= n-len ; i++ ) {
            curr = ( curr * BASE - ( pBase * (s[i-1] - 'a') ) % MOD + (s[i+len-1] - 'a') + MOD ) % MOD;
            auto it = index.find(curr);
            if(it != index.end())
                return it->second;
            index[curr] = i;
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int n = s.length();
        int ansSt = 0 , ansLen = 0;
        int l = 1 , r = n;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int st = f(mid,n,s);
            if(st == -1)
                r = mid-1;
            else
                l = mid+1 , ansSt = st , ansLen = mid;
        }
        string ans = s.substr(ansSt,ansLen);
        return ans;
    }
};