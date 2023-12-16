class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.length() , ans = 0;
        for( int i = 1 ; i < n ; i++ )
            if(abs(s[i]-s[i-1]) <= 1)
                ans++, i++;
        return ans;
    }
};
