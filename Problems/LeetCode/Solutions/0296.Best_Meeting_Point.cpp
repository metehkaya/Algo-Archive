class Solution {
public:
    int minTotalDistance(vector<vector<int>>& ar) {
        int n = ar.size();
        if(n == 0)
            return 0;
        int m = ar[0].size();
        vector<int> x,y;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
        n = x.size();
        if(n == 0)
            return 0;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int ans = 0;
        int X = x[n/2];
        int Y = y[n/2];
        for( int i = 0 ; i < n ; i++ ) {
            ans += abs(X-x[i]);
            ans += abs(Y-y[i]);
        }
        return ans;
    }
};