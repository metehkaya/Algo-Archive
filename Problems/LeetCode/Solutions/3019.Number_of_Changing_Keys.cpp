class Solution {
public:
    int char2int(char c) {
        return c >= 'a' ? c-'a' : c-'A';
    }
    int countKeyChanges(string s) {
        int n = s.length() , ans = 0;
        for( int i = 1 ; i < n ; i++ ) {
            char c1 = s[i-1] , c2 = s[i];
            int v1 = char2int(c1) , v2 = char2int(c2);
            ans += (v1 != v2);
        }
        return ans;
    }
};