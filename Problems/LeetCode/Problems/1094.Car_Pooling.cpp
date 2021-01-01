class Solution {
public:
    static const int maxs = 1001;
    int cnt[maxs];
    bool carPooling(vector<vector<int>>& ar, int cap) {
        memset(cnt,0,sizeof(cnt));
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i][1]] += ar[i][0] , cnt[ar[i][2]] -= ar[i][0];
        int sum = 0;
        for( int i = 0 ; i < maxs ; i++ ) {
            sum += cnt[i];
            if(sum > cap)
                return false;
        }
        return true;
    }
};