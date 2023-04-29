class Solution {
public:
    static const int maxn = 100000;
    const int mod = 1000000007;
    int tree[4*maxn];
    int query(int cx , int cy , int qx , int qy , int id) {
        if(qy < cx || cy < qx)
            return 0;
        if(qx <= cx && cy <= qy)
            return tree[id];
        int mid = (cx+cy) >> 1;
        int l = query(cx,mid,qx,qy,id*2+1);
        int u = query(mid+1,cy,qx,qy,id*2+2);
        return l+u;
    }
    void update(int cx , int cy , int q , int id) {
        if(cy < q || q < cx)
            return;
        tree[id]++;
        if(cx == cy)
            return;
        int mid = (cx+cy) >> 1;
        update(cx,mid,q,id*2+1);
        update(mid+1,cy,q,id*2+2);
    }
    int createSortedArray(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int l = query(1,maxn,1,ar[i]-1,0);
            int u = query(1,maxn,ar[i]+1,maxn,0);
            ans = (ans + min(l,u)) % mod;
            update(1,maxn,ar[i],0);
        }
        return ans;
    }
};