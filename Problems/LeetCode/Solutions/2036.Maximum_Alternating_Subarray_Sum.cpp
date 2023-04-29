typedef long long LL;

class Solution {
public:
    LL maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();
        LL min_1 = 0 , min_2 = LLONG_MAX , ans = LLONG_MIN , sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += (i%2 == 0) ? nums[i] : -nums[i];
            ans = max(ans,sum-min_1);
            if(i)
                ans = max(ans,-sum-min_2);
            if(i%2 == 0)
                min_2 = min(min_2,-sum);
            else
                min_1 = min(min_1,sum);
        }
        return ans;
    }
};
