class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> nxt(n+1,-1);
        for( int i = 0 ; i <= n ; i++ ) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            nxt[l] = max(nxt[l], r);
        }
        int ans = 0, currStop = 0, nxtStop = 0;
        for( int i = 0 ; i < n ; i++ ) {
            nxtStop = max(nxtStop, nxt[i]);
            if(i == currStop) {
                if(nxtStop <= i)
                    return -1;
                ans++;
                currStop = nxtStop;
            }
        }
        return ans;
    }
};