typedef long long LL;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> cnt(n,0);
        vector<LL> available(m,0);
        sort(meetings.begin(),meetings.end());
        for( int i = 0 ; i < m ; i++ ) {
            int idx = -1;
            for( int j = 0 ; j < n ; j++ )
                if(available[j] <= meetings[i][0]) {
                    idx = j;
                    break;
                }
            if(idx == -1) {
                idx = 0;
                for( int j = 1 ; j < n ; j++ )
                    if(available[j] < available[idx])
                        idx = j;
            }
            cnt[idx]++;
            available[idx] = max(available[idx],(LL)meetings[i][0]) + (meetings[i][1] - meetings[i][0]);
        }
        int best = 0;
        for( int i = 1 ; i < n ; i++ )
            if(cnt[i] > cnt[best])
                best = i;
        return best;
    }
};
