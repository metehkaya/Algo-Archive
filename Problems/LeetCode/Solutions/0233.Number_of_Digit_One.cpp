class Solution {
public:
    int countDigitOne(int N) {
        string s = to_string(N);
        int n = s.length();
        vector<int> p10(n,1);
        for( int i = 1 ; i < n ; i++ )
            p10[i] = p10[i-1]*10;
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++ ) {
            int c = s[i]-'0';
            ans += c*(n-1-i)*p10[n-2-i];
            if(c > 1)
                ans += p10[n-1-i];
            else if(c == 1)
                ans += N % p10[n-1-i]+1;
        }
        if(s[n-1] >= '1')
            ans++;
        return ans;
    }
};
