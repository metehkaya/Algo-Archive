class Solution {
public:
    int f(int x) {
        string s = to_string(x*x);
        int n = s.length();
        for( int bmask = 0 ; bmask < (1<<(n-1)) ; bmask++ ) {
            int val = s[0]-'0' , sum = 0;
            for( int i = 0 ; i < n-1 ; i++ ) {
                if(bmask & (1<<i))
                    sum += val , val = s[i+1]-'0';
                else
                    val = 10*val+s[i+1]-'0';
            }
            sum += val;
            if(sum == x)
                return x*x;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            ans += f(i);
        return ans;
    }
};
