class Solution {
public:
    bool queryString(string s, int N) {
        int n = s.length();
        if(N > 31*n)
            return false;
        bool var[N+1];
        memset(var,0,sizeof(var));
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '1') {
                int val = 0;
                for( int j = i ; j < min(n,i+31) ; j++ ) {
                    val <<= 1;
                    val |= s[j]-'0';
                    if(val > N)
                        break;
                    var[val]  = true;
                }
            }
        bool ans = true;
        for( int i = 1 ; i <= N && ans ; i++ )
            if(!var[i])
                ans = false;
        return ans;
    }
};
