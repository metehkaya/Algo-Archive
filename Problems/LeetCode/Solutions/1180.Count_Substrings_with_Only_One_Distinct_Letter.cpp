class Solution {
public:
    int countLetters(string s) {
        int n = s.length() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int d = j-i;
            ans += d*(d+1)/2;
        }
        return ans;
    }
};