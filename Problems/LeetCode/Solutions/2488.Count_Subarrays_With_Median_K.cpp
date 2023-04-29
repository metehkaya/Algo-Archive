class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size() , sum = 0;
        vector<int> cnt(2*n+2,0);
        int curr = n , ans = 0;
        bool found = false;
        cnt[curr]++;
        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] == k)
                found = true;
            else if(nums[i] > k)
                curr++;
            else
                curr--;
            if(found)
                ans += cnt[curr] + cnt[curr-1];
            else
                cnt[curr]++;
        }
        return ans;
    }
};
