class Solution {
public:
    static const int maxn = 100003;
    int st[maxn];
    vector<int> canSeePersonsCount(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans(n,0);
        int idx = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(idx) {
                int l = 1 , r = idx;
                int last1 = -1;
                int last2 = -1;
                while(l <= r) {
                    int m = (l+r) >> 1;
                    if(ar[st[m]] < ar[i]) {
                        last1 = m;
                        r = m-1;
                    }
                    else {
                        last2 = m;
                        l = m+1;
                    }
                }
                if(last2 != -1)
                    ans[i] = idx-last2+1;
                else
                    ans[i] = idx-last1+1;
            }
            while(idx && ar[i] >= ar[st[idx]])
                idx--;
            st[++idx] = i;
        }
        return ans;
    }
};