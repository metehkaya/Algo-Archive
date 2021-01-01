class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        int n = s.length();
        int m = t.length();
        int cntWord = 0;
        for( int i = 0 ; i <= n-m ; i++ )
            if( i == 0 || s[i-1] == ' ' ) {
                cntWord++;
                bool ok = true;
                for( int j = 0 ; j < m ; j++ )
                    if( s[i+j] != t[j] ) {
                        ok = false;
                        break;
                    }
                if(ok)
                    return cntWord;
            }
        return -1;
    }
};