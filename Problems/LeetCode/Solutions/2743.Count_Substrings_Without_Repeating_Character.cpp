class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int n = s.length() , ans = 0;
        vector<bool> var(256,false);
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n and !var[s[j]])
                var[s[j++]] = true;
            ans += j-i;
            var[s[i]] = false;
        }
        return ans;
    }
};
