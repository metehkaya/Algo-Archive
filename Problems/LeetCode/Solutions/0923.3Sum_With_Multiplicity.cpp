class Solution {
public:
    const int MAXV = 101;
    const int MOD = (int) 1e9 + 7;
    int threeSumMulti(vector<int>& ar, int target) {
        int n = ar.size() , ans = 0;
        vector<int> cnt(MAXV,0);
        for( int i = 0 ; i < n ; i++ ) {
            int sum = target - ar[i];
            for( int j = 0 ; 2*j <= sum ; j++ ) {
                int k = sum - j , add;
                if(max(j,k) >= MAXV)
                    continue;
                if(j != k)
                    add = cnt[j] * cnt[k];
                else
                    add = cnt[j] * (cnt[j]-1) / 2;
                ans = (ans + add) % MOD;
            }
            cnt[ar[i]]++;
        }
        return ans;
    }
};