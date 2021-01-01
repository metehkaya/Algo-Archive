class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& ar, int add) {
        int n = ar.size();
        vector<bool> ans(n,false);
        int mx = -1;
        for( int i = 0 ; i < n ; i++ )
            mx = max( mx , ar[i] );
        for( int i = 0 ; i < n ; i++ )
            ans[i] = ( ar[i] + add ) >= mx;
        return ans;
    }
};