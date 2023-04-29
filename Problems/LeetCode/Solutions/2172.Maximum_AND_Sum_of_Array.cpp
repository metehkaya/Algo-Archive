class Solution {
public:
    int maximumANDSum(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> p3(k+1);
        p3[0] = 1;
        for( int i = 1 ; i <= k ; i++ )
            p3[i] = 3*p3[i-1];
        vector<int> dp(p3[k],0);
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> dpnext(p3[k],0);
            for( int bmask = 0 ; bmask < p3[k] ; bmask++ )
                for( int j = 0 ; j < k ; j++ )
                    if(bmask / p3[j] % 3 < 2) {
                        int bmask2 = bmask+p3[j];
                        dpnext[bmask2] = max(dpnext[bmask2] , dp[bmask]+(ar[i]&(j+1)));
                    }
            swap(dp,dpnext);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
