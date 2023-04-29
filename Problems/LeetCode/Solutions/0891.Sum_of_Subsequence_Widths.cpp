#define mod 1000000007
#define pb push_back
typedef long long LL;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            v.pb(nums[i]);
        sort(v.begin(),v.end());
        vector<int> p2(n);
        p2[0] = 1;
        for( int i = 1 ; i < n ; i++ )
            p2[i] = (p2[i-1] * 2) % mod;
        LL mnsum = 0 , mxsum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            mnsum += (LL) p2[n-1-i] * v[i];
            mnsum %= mod;
            mxsum += (LL) p2[i] * v[i];
            mxsum %= mod;
        }
        return (mxsum-mnsum+mod) % mod;
    }
};
