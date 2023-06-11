typedef long long LL;

class Solution {
public:
    const int mod = (int)1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<LL> v;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'L')
                v.push_back(nums[i]-d);
            else
                v.push_back(nums[i]+d);
        sort(v.begin(),v.end());
        int ans = 0 , sum = v[0];
        for( int i = 1 ; i < n ; i++ ) {
            ans += (v[i]*i - sum + mod) % mod;
            ans %= mod;
            sum = (sum + v[i]) % mod;
        }
        return ans;
    }
};
