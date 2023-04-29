class Solution {
public:
    int letter2Number(char c) {
        if(c >= 'a')
            return c-'a';
        return c-'A'+26;
    }
    int numJewelsInStones(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<bool> var(52, false);
        for( int i = 0 ; i < n ; i++ )
            var[letter2Number(s[i])] = true;
        int ans = 0;
        for( int i = 0 ; i < m ; i++ )
            if( var[letter2Number(t[i])] )
                ans++;
        return ans;
    }
};