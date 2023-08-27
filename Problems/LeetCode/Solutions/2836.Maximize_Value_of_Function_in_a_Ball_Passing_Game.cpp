typedef long long LL;

class Solution {
public:
    static const int maxk = 34;
    LL getMaxFunctionValue(vector<int>& receiver, long long t) {
        int n = receiver.size();
        vector<int> nxt[n];
        vector<LL> sum[n];
        for( int i = 0 ; i < n ; i++ ) {
            sum[i].push_back(receiver[i]);
            nxt[i].push_back(receiver[i]);
        }
        for( int k = 1 ; k < maxk ; k++ ) 
            for( int i = 0 ; i < n ; i++ ) {
                int curr = nxt[i][k-1];
                int nxt_curr = nxt[curr][k-1];
                LL total = sum[i][k-1] + sum[curr][k-1];
                nxt[i].push_back(nxt_curr);
                sum[i].push_back(total);
            }
        LL ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int curr = i;
            LL total = i;
            for( int k = 0 ; k < maxk ; k++ )
                if(t & (1LL<<k)) {
                    total += sum[curr][k];
                    curr = nxt[curr][k];
                }
            ans = max(ans,total);
        }
        return ans;
    }
};
