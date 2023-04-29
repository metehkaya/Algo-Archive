#define pb push_back

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size() , add = 0 , total = 0;
        vector<int> pos;
        vector<int> sum;
        for( int i = 0 ; i < n ; i++ ) {
            if(fruits[i][0] == startPos)
                add = fruits[i][1];
            else {
                total += fruits[i][1];
                pos.pb(fruits[i][0]);
                sum.pb(total);
            }
        }
        n = pos.size();
        int ans = 0 , idx = lower_bound(pos.begin(),pos.end(),startPos) - pos.begin();
        for( int i = 0 ; i < idx ; i++ )
            if(startPos - pos[i] <= k) {
                int f = sum[idx-1] - (i > 0 ? sum[i-1] : 0) , best = 0;
                int l = idx , r = n-1;
                while(l <= r) {
                    int m = (l+r) >> 1;
                    int cost = startPos - pos[i] + pos[m] - pos[i];
                    if(cost <= k) {
                        best = sum[m] - sum[idx-1];
                        l = m+1;
                    }
                    else
                        r = m-1;
                }
                ans = max(ans,best+f);
            }
        for( int i = idx ; i < n ; i++ )
            if(pos[i] - startPos <= k) {
                int f = sum[i] - (idx > 0 ? sum[idx-1] : 0) , best = 0;
                int l = 0 , r = idx-1;
                while(l <= r) {
                    int m = (l+r) >> 1;
                    int cost = pos[i] - startPos + pos[i] - pos[m];
                    if(cost <= k) {
                        best = sum[idx-1] - (m > 0 ? sum[m-1] : 0);
                        r = m-1;
                    }
                    else
                        l = m+1;
                }
                ans = max(ans,best+f);
            }
        return ans+add;
    }
};
