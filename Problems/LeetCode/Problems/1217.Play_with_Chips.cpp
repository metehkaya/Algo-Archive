class Solution {
public:
    int minCostToMoveChips(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(2,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]%2]++;
        return min(cnt[0],cnt[1]);
    }
};