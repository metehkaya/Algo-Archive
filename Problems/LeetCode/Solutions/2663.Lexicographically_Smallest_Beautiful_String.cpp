class Solution {
public:
    bool check(string& s , int idx , char ch) {
        if(idx >= 1 and ch == s[idx-1])
            return false;
        if(idx >= 2 and ch == s[idx-2])
            return false;
        return true;
    }
    string smallestBeautifulString(string s, int k) {
        int n = s.length();
        char last_ch = 'a' + k-1;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( char ch = s[i]+1 ; ch <= last_ch ; ch++ )
                if(check(s,i,ch)) {
                    string ans = s;
                    ans[i] = ch;
                    for( int j = i+1 ; j < n ; j++ )
                        for( char ch = 'a' ; ch <= last_ch ; ch++ )
                            if(check(ans,j,ch)) {
                                ans[j] = ch;
                                break;
                            }
                    return ans;
                }
        return "";
    }
};
