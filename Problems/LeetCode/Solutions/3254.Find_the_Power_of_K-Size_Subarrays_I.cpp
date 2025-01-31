class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for( int i = 0 ; i <= n-k ; i++ ) {
            bool ok = true;
            for( int j = i+1 ; j < i+k ; j++ )
                if(nums[j] != nums[j-1]+1)
                    ok = false;
            int res = ok ? nums[i+k-1] : -1;
            ans.push_back(res);
        }
        return ans;
    }
};
