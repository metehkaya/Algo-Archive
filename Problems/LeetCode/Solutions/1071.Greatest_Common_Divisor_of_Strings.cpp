class Solution {
public:
    int gcd(int x, int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    bool check(string& str1, string& str2, int k) {
        string s = str1.substr(0,k);
        for( int i = 0 ; i < str1.length() ; i++ )
            if( str1[i] != s[i%k] )
                return false;
        for( int i = 0 ; i < str2.length() ; i++ )
            if( str2[i] != s[i%k] )
                return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int g = gcd(n,m);
        string ans = "";
        for( int i = g ; i >= 1 ; i-- )
            if( n%i == 0 && m%i == 0 && check(str1,str2,i) ) {
                ans = str1.substr(0,i);
                break;
            }
        return ans;
    }
};