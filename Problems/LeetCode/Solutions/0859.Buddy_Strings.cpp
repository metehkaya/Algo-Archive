class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
            return false;
        vector<int> cntS(26,0);
        vector<int> cntT(26,0);
        for( int i = 0 ; i < n ; i++ )
            cntS[s[i]-'a']++;
        for( int i = 0 ; i < n ; i++ )
            cntT[t[i]-'a']++;
        int diff = 0 , mx = 0;
        for( int i = 0 ; i < n ; i++ )
            diff += s[i] != t[i];
        for( int i = 0 ; i < 26 ; i++ ) {
            if(cntS[i] != cntT[i])
                return false;
            mx = max(mx,cntS[i]);
        }
        if(diff == 2 || (diff == 0 && mx > 1))
            return true;
        return false;
    }
};