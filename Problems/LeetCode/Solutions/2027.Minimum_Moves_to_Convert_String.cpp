class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length() , ans = 0;
        for( int i = 0 ; i <= n-3 ; i++ )
            if(s[i] == 'X')
                s[i] = s[i+1] = s[i+2] = 'O' , ans++;
        if(s[n-2] == 'X' || s[n-1] == 'X')
            ans++;
        return ans;
    }
};