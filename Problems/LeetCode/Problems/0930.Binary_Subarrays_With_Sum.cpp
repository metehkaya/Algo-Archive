class Solution {
public:
    int numSubarraysWithSum(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        vector<int> cnt(n+1,0);
        cnt[0] = 1;
        for( int i = 0 , s = 0 ; i < n ; i++ ) {
            s += ar[i];
            if(s >= k)
                ans += cnt[s-k];
            cnt[s]++;
        }
        return ans;
    }
};