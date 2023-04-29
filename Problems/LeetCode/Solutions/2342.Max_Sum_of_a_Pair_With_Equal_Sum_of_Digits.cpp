class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> v[82];
        for( int i = 0 ; i < nums.size() ; i++ ) {
            int x = nums[i] , sum = 0;
            while(x) {
                sum += x%10;
                x /= 10;
            }
            v[sum].push_back(nums[i]);
        }
        int ans = -1;
        for( int i = 0 ; i < 82 ; i++ )
            if(v[i].size() >= 2) {
                int sz = v[i].size();
                sort(v[i].begin(),v[i].end());
                ans = max(ans,v[i][sz-1]+v[i][sz-2]);
            }
        return ans;
    }
};
