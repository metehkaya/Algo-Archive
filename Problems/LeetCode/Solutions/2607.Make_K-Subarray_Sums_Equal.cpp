class Solution {
public:
    long long makeSubKSumEqual(vector<int>& ar, int k) {
        int n = ar.size();
        int g = __gcd(n,k);
        long long ans = 0;
        for( int i = 0 ; i < g ; i++ ) {
            vector<int> v;
            for( int j = i ; j < n ; j += g )
                v.push_back(ar[j]);
            sort(v.begin(),v.end());
            int sz = v.size();
            int pivot = v[sz/2];
            for( int j = 0 ; j < sz ; j++ )
                ans += abs(v[j]-pivot);
        }
        return ans;
    }
};
