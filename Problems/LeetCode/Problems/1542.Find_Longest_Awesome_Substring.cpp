class Solution {
public:
    static const int maxs = (1<<10);
    int longestAwesome(string s) {
        vector<int> idx(maxs,-1);
        idx[0] = 0;
        int n = s.length() , ans = 1 , curr = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int c = s[i-1]-'0';
            curr ^= (1<<c);
            if(idx[curr] == -1)
                idx[curr] = i;
            int len = i-idx[curr];
            for( int j = 0 ; j < 10 ; j++ ) {
                int mask = (curr ^ (1<<j));
                if(idx[mask] != -1)
                    len = max(len,i-idx[mask]);
            }
            ans = max(ans,len);
        }
        return ans;
    }
};