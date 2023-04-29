class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<int> sum({0});
        for( int i = 0 ; i < n ; i++ )
            sum.push_back(sum[i]+v[i]);
        int l = 1 , r = sum[n] , ans = -1;
        while(l <= r) {
            int diff = (l+r) >> 1;
            int total = 0;
            for( int i = 1 , j = 0 ; i <= n ; i++ ) {
                while(j < i and sum[i]-sum[j] > diff)
                    j++;
                total += i-j;
            }
            if(total >= k)
                ans = diff , r = diff-1;
            else
                l = diff+1;
        }
        return ans;
    }
};
