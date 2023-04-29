class Solution {
public:
    int numOfStrings(vector<string>& ar, string t) {
        int ans = 0;
        int m = t.length();
        for( int i = 0 ; i < ar.size() ; i++ ) {
            string s = ar[i];
            int n = s.length();
            for( int j = 0 ; j <= m-n ; j++ ) {
                bool ok = true;
                for( int k = 0 ; k < n ; k++ )
                    if(s[k] != t[j+k])
                        ok = false;
                if(ok) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};