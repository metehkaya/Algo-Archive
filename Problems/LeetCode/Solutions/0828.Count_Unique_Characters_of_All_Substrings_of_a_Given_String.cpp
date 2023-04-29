class Solution {
public:
    int last1[26];
    int last2[26];
    int uniqueLetterString(string s) {
        int n = s.length() , ans = 0;
        memset(last1,-1,sizeof(last1));
        memset(last2,-1,sizeof(last2));
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'A';
            last1[c] = last2[c];
            last2[c] = i;
            for( int j = 0 ; j < 26 ; j++ )
                ans += last2[j]-last1[j];
        }
        return ans;
    }
};