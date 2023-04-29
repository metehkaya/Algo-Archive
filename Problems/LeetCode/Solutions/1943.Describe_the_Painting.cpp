typedef long long LL;

class Solution {
public:
    static const int maxs = 100001;
    LL add[maxs];
    int open[maxs];
    int close[maxs];
    vector<vector<LL>> splitPainting(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            open[ar[i][0]]++;
            close[ar[i][1]]++;
            add[ar[i][0]] += ar[i][2];
            add[ar[i][1]] -= ar[i][2];
        }
        int s = -1;
        int cnt = 0;
        LL curr = 0;
        vector<vector<LL>> ans;
        for( int i = 1 ; i < maxs ; i++ ) {
            if(open[i] || close[i]) {
                cnt += open[i]-close[i];
                if(s != -1) {
                    ans.push_back({s,i,curr});
                    if(cnt == 0)
                        s = -1;
                    else
                        s = i;
                }
                else
                    s = i;
            }
            curr += add[i];
        }
        return ans;
    }
};