class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i ; j < n ; j++ ) {
                vector<int> v;
                for( int k = 0 ; k < n ; k++ )
                    if(k < i or k > j)
                        v.push_back(nums[k]);
                bool ok = true;
                for( int i = 1 ; i < v.size() ; i++ )
                    if(v[i] <= v[i-1])
                        ok = false;
                ans += ok;
            }
        return ans;
    }
};
