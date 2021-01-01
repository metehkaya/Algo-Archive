class Solution {
public:
    int numIdenticalPairs(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(101,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        int ans = 0;
        for( int i = 1 ; i <= 100 ; i++ )
            ans += cnt[i] * (cnt[i]-1) / 2;
        return ans;
    }
};