class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        vector<long long> cnt(61,0);
        for(int x : s) {
            int b =  __builtin_popcount(x);
            cnt[b]++;
        }
        long long ans = 0;
        for( int i = 0 ; i < 61 ; i++ )
            for( int j = max(k-i,0) ; j < 61 ; j++ ) {
                long long ci = cnt[i];
                long long cj = cnt[j];
                ans += ci*cj;
            }
        return ans;
    }
};
