class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& ar) {
        int ans = 0;
        int n = ar.size() , m = ar[0].size();
        vector<int> hist(m,0);
        for( int r = 0 ; r < n ; r++ ) {
            for( int i = 0 ; i < m ; i++ )
                hist[i] = (hist[i]+1) * ar[r][i];
            vector<int> v = hist;
            sort(v.begin(),v.end());
            for( int i = 0 ; i < m ; i++ )
                ans = max(ans,v[i]*(m-i));
        }
        return ans;
    }
};
