class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long ans = 0;
        sort(v.begin(),v.end());
        reverse(v.begin(), v.end());
        for( int i = 0 ; i < k ; i++ )
            ans += max(v[i]-i,0);
        return ans;
    }
};
