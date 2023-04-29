class Solution {
public:
    bool sumGame(string s) {
        int n = s.length() , sum = 0 , cnt = 0;
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            int side = (i < n/2) ? 1 : -1;
            if(c == '?')
                cnt += side;
            else
                sum += side * (c-'0');
        }
        return 2*sum != -9*cnt;
    }
};