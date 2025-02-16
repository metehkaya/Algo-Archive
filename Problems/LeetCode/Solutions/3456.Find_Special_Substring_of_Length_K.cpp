class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and s[i] == s[j])
                j++;
            if(j-i == k)
                return true;
        }
        return false;
    }
};