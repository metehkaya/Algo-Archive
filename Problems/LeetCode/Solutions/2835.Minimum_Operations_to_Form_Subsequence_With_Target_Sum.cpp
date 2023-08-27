class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> cnt(32,0);
        for(int num : nums)
            cnt[__builtin_popcount(num-1)]++;
        for( int b = 0 ; b <= 30 ; b++ ) {
            if(k & (1<<b)) {
                if(cnt[b])
                    cnt[b]--;
                else {
                    bool ok = false;
                    for( int i = b+1 ; i <= 30 ; i++ )
                        if(cnt[i]) {
                            ok = true;
                            cnt[i]--;
                            ans += i-b;
                            for( int j = b ; j < i ; j++ )
                                cnt[j]++;
                            break;
                        }
                    if(!ok)
                        return -1;
                }
            }
            cnt[b+1] += cnt[b]/2;
        }
        return ans;
    }
};
