typedef long long LL;

class Solution {
public:
    const LL add = (1ll << 34);
    const LL maxs = (1ll << 36);
    map<LL,int> tree;
    void update(LL x) {
        x += add;
        while(x <= maxs) {
            tree[x]++;
            x += (x & (-x));
        }
    }
    int query(LL x) {
        x += add;
        int res = 0;
        while(x) {
            res += tree[x];
            x -= (x & (-x));
        }
        return res;
    }
    int reversePairs(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            ans += query(ar[i]-1);
            update(2LL*ar[i]);
        }
        return ans;
    }
};