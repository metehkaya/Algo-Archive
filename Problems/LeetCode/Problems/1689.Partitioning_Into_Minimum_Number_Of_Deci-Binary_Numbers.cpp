class Solution {
public:
    int minPartitions(string s) {
        int n = s.length() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans = max(ans,s[i]-'0');
        return ans;
    }
};