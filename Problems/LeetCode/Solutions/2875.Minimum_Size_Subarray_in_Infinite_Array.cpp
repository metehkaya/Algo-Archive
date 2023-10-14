class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum = 0;
        for(int x : nums)
            sum += x;
        int add = n * (target / sum);
        target %= sum;
        map<int,int> mp;
        sum = mp[0] = 0;
        int ans = n;
        for( int i = 0 ; i < 2*n ; i++ ) {
            sum += nums[i%n];
            mp[sum] = i+1;
            if(mp.find(sum-target) != mp.end())
                ans = min(ans,i+1-mp[sum-target]);
        }
        return ans == n ? -1 : ans+add;
    }
};
