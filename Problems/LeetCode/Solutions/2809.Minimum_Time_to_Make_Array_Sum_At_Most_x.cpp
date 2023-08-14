class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        int sum1 = 0 , sum2 = 0;
        vector<pair<int,int>> v;
        for( int i = 0 ; i < n ; i++ ) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            v.push_back(make_pair(nums2[i],nums1[i]));
        }
        sort(v.begin(), v.end());
        vector<int> dp(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            int add = v[i].first;
            int init = v[i].second;
            for( int j = n-1 ; j >= 0 ; j-- )
                dp[j+1] = max(dp[j+1], dp[j]+init+add*(j+1));
        }
        for( int i = 0 ; i <= n ; i++ )
            if(sum1+sum2*i - dp[i] <= x)
                return i;
        return -1;
    }
};
