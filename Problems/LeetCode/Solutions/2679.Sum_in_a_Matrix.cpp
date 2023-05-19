class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size() , m = nums[0].size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            sort(nums[i].begin(),nums[i].end());
        for( int j = 0 ; j < m ; j++ ) {
            int add = 0;
            for( int i = 0 ; i < n ; i++ )
                add = max(add,nums[i][j]);
            ans += add;
        }
        return ans;
    }
};
