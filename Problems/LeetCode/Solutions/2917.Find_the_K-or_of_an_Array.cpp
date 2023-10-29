class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> cnt(31,0);
        for(int x : nums)
            for( int i = 0 ; i < 31 ; i++ )
                if(x & (1<<i))
                    cnt[i]++;
        int ans = 0;
        for( int i = 0 ; i < 31 ; i++ )
            if(cnt[i] >= k)
                ans |= (1<<i);
        return ans;
    }
};
