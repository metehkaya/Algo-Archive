class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        vector<int> cnt(50,0);
        for(int x : nums)
            for( int k = 0 ; k < 30 ; k++ )
                if(x & (1<<k))
                    cnt[k]++;
        long long ans = 0;
        for( int i = 0 ; i < 49 ; i++ )
            if(cnt[i]) {
                ans |= (1ll << i);
                cnt[i+1] += cnt[i]/2;
            }
        return ans;
    }
};
