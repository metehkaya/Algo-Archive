class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        vector<int> cnt(60,0);
        for( int i = 0 ; i < n ; i++ ) {
            int v1 = ar[i] % 60;
            int v2 = (60-v1) % 60;
            ans += cnt[v2];
            cnt[v1]++;
        }
        return ans;
    }
};