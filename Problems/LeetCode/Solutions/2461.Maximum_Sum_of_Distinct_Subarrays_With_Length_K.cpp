class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() , cnt = 0;
        map<int,int> mp;
        long long sum = 0 , ans = 0;
        for( int i = 0 ; i < k ; i++ ) {
            sum += nums[i];
            if(++mp[nums[i]] == 1)
                cnt++;
        }
        if(cnt == k)
            ans = sum;
        for( int i = k ; i < n ; i++ ) {
            sum += nums[i];
            sum -= nums[i-k];
            if(++mp[nums[i]] == 1)
                cnt++;
            if(--mp[nums[i-k]] == 0)
                cnt--;
            if(cnt == k)
                ans = max(ans,sum);
        }
        return ans;
    }
};
