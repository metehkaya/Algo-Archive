class Solution {
public:
    int l[26],r[26];
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1 , n = s.length();
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            if(l[c] == -1)
                l[c] = i;
            r[c] = i;
        }
        for( int i = 0 ; i < 26 ; i++ )
            if(l[i] != r[i])
                ans = max(ans,r[i]-l[i]-1);
        return ans;
    }
};