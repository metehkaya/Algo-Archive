class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long curr = 0 , ans = 0;
        int n = nums.size();
        map<int,int> mp;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n and curr < k)
                curr += mp[nums[j++]]++;
            if(curr >= k)
                ans += n-j+1;
            curr -= --mp[nums[i]];
        }
        return ans;
    }
};
