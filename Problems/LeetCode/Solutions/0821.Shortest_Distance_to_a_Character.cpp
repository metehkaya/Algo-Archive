class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n,INT_MAX);
        for( int i = 0 , bef = -1 ; i < n ; i++ ) {
            if(s[i] == c)
                bef = i;
            if(bef != -1)
                ans[i] = min(ans[i],abs(i-bef));
        }
        for( int i = n-1 , bef = -1 ; i >= 0 ; i-- ) {
            if(s[i] == c)
                bef = i;
            if(bef != -1)
                ans[i] = min(ans[i],abs(i-bef));
        }
        return ans;
    }
};