class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int K = (1<<k);
        vector<bool> var(K,false);
        int n = s.length();
        if(n < k)
            return false;
        int curr = 0;
        for( int i = 0 ; i < k ; i++ )
            curr += (s[i] - '0') * (1 << (k-i-1));
        var[curr] = true;
        for( int i = k ; i < n ; i++ ) {
            curr -= (s[i-k] - '0') * (1 << (k-1));
            curr *= 2;
            curr += (s[i] - '0');
            var[curr] = true;
        }
        for( int i = 0 ; i < K ; i++ )
            if(!var[i])
                return false;
        return true;
    }
};