class Solution {
public:
    int gcd(int x, int y) {
        if(!y)
            return x;
        return gcd(y, x%y);
    }
    string int2str(int num) {
        string s = "";
        while(num) {
            int dig = num % 10;
            num /= 10;
            char c = '0' + dig;
            s.push_back(c);
        }
        reverse(s.begin(), s.end());
        return s;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for( int i = 1 ; i < n ; i++ )
            for( int j = i+1 ; j <= n ; j++ )
                if( gcd(i,j) == 1 ) {
                    string s = int2str(i) + "/" + int2str(j);
                    ans.push_back(s);
                }
        return ans;
    }
};