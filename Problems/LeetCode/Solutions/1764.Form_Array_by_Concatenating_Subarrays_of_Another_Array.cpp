class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int m = groups.size();
        int curr = 0;
        for( int i = 0 ; curr < m && i+groups[curr].size() <= n ; i++ ) {
            bool ok = true;
            int sz = groups[curr].size();
            for( int j = 0 ; j < sz ; j++ )
                if(nums[i+j] != groups[curr][j])
                    ok = false;
            if(ok) {
                curr++;
                i += sz-1;
            }
        }
        return curr == m;
    }
};