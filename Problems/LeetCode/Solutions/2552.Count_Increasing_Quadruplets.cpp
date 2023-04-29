typedef long long LL;

class Solution {
public:
    LL countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<LL>> dp_left(n,vector<LL>(n+1,0));
        vector<vector<LL>> dp_right(n,vector<LL>(n+1,0));
        for( int i = 0 ; i < n ; i++ ) {
            if(i)
                for( int j = 1 ; j <= n ; j++ )
                    dp_left[i][j] = dp_left[i-1][j];
            for( int j = nums[i] ; j <= n ; j++ )
                dp_left[i][j]++;
        }
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(i+1 < n)
                for( int j = 1 ; j <= n ; j++ )
                    dp_right[i][j] = dp_right[i+1][j];
            for( int j = nums[i] ; j <= n ; j++ )
                dp_right[i][j]++;
        }
        LL ans = 0;
        for( int i = 1 ; i < n-2 ; i++ )
            for( int j = i+1 ; j < n-1 ; j++ )
                if(nums[i] > nums[j]) {
                    LL l = dp_left[i-1][nums[j]-1];
                    LL r = dp_right[j+1][n] - dp_right[j+1][nums[i]];
                    ans += l*r;
                }
        return ans;
    }
};
