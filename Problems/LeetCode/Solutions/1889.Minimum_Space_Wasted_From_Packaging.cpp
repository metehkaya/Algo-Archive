typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        LL total = 0;
        for( int i = 0 ; i < n ; i++ )
            total += packages[i];
        sort(packages.begin(),packages.end());
        LL ans = (1LL << 60);
        int m = boxes.size();
        for( int i = 0 ; i < m ; i++ ) {
            vector<int> v = boxes[i];
            sort(v.begin(),v.end());
            int k = v.size();
            if(v[k-1] >= packages[n-1]) {
                LL sum = (LL)v[k-1]*n - total;
                for( int j = k-2 ; j >= 0 ; j-- ) {
                    LL diff = v[j+1]-v[j];
                    int idx = upper_bound(packages.begin(), packages.end(), v[j]) - packages.begin();
                    sum -= idx*diff;
                }
                ans = min(ans,sum);
            }
        }
        return (ans == (1LL << 60)) ? -1 : ans % mod;
    }
};