class Solution {
public:
    int n,ans;
    int cnts[2];
    void f(string& s , string& t , int c0 , int c1) {
        if(cnts[0] != c0 || cnts[1] != c1)
            return;
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            cnt += s[i] != t[i];
        ans = min(ans,cnt/2);
    }
    int minSwaps(string s) {
        n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnts[s[i]-'0']++;
        ans = INT_MAX;
        string t;
        t = "";
        for( int i = 0 ; i < n ; i++ )
            t.push_back('0'+(i%2));
        f(s,t,(n+1)/2,n/2);
        t = "";
        for( int i = 0 ; i < n ; i++ )
            t.push_back('1'-(i%2));
        f(s,t,n/2,(n+1)/2);
        return (ans == INT_MAX) ? -1 : ans;
    }
};