class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        int n_add = 10 / __gcd(10,a);
        int n_rotate = n / __gcd(n,b);
        string ans = s;
        for( int t_rotate = 0 ; t_rotate < n_rotate ; t_rotate++ ) {
            int r = t_rotate * b % n;
            string t = s;
            for( int i = 0 ; i < n ; i++ )
                t[i] = s[(i+r)%n];
            string best = t;
            if(n%2 == 1 or b%2 == 1)
                for( int t_add = 0 ; t_add < n_add ; t_add++ ) {
                    string res = t;
                    int add = t_add * a % 10;
                    for( int i = 0 ; i < n ; i += 2 ) {
                        int d = t[i]-'0';
                        d = (d + add) % 10;
                        res[i] = '0'+d;                    
                    }
                    best = min(best,res);
                }
            t = best;
            for( int t_add = 0 ; t_add < n_add ; t_add++ ) {
                string res = t;
                int add = t_add * a % 10;
                for( int i = 1 ; i < n ; i += 2 ) {
                    int d = t[i]-'0';
                    d = (d + add) % 10;
                    res[i] = '0'+d;                    
                }
                ans = min(ans,res);
            }
        }
        return ans;
    }
};
