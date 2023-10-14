class Solution {
public:
    int minProcessingTime(vector<int>& x, vector<int>& y) {
        int n = x.size() , ans = 0;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for( int i = 0 ; i < n ; i++ )
            ans = max(ans,x[i]+y[4*n-1-4*i]);
        return ans;
    }
};
