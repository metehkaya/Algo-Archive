class Solution {
public:
    static const int maxs = 50000;
    int l[maxs],r[maxs],cnt[maxs];
    int findShortestSubArray(vector<int>& ar) {
        int n = ar.size();
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        int freq = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i];
            r[x] = i;
            if(l[x] == -1)
                l[x] = i;
            int f = ++cnt[x];
            if(f > freq) {
                freq = f;
                v.clear();
                v.push_back(x);
            }
            else if(f == freq)
                v.push_back(x);
        }
        int ans = INT_MAX;
        int sz = v.size();
        for( int i = 0 ; i < sz ; i++ ) {
            int x = v[i];
            ans = min(ans,r[x]-l[x]+1);
        }
        return ans;
    }
};