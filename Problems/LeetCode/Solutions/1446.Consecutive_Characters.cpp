class Solution {
public:
    int maxPower(string s) {
        int n = s.length() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            ans = max( ans , j-i );
        }
        return ans;
    }
};