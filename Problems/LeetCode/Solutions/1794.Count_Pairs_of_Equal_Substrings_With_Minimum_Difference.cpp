class Solution {
public:
    int countQuadruples(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> idx1(26,-1);
        vector<int> idx2(26,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            if(idx1[c] == -1)
                idx1[c] = i;
        }
        for( int i = 0 ; i < m ; i++ ) {
            int c = t[i]-'a';
            idx2[c] = i;
        }
        int mn = INT_MAX , ans = 0;
        for( int i = 0 ; i < 26 ; i++ )
            if(idx1[i] != -1 and idx2[i] != -1) {
                int diff = idx1[i]-idx2[i];
                if(diff < mn)
                    mn = diff , ans = 1;
                else if(diff == mn)
                    ans++;
            }
        return ans;
    }
};
