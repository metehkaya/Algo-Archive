class Solution {
public:
    static const int maxn = 100000;
    int tree[4*maxn+5];
    void update(int cx , int cy , int q , int val , int id) {
        if(cy < q || q < cx)
            return;
        tree[id] = max(tree[id],val);
        if(cx == cy)
            return;
        int mid = (cx+cy)>>1;
        update(cx,mid,q,val,2*id);
        update(mid+1,cy,q,val,2*id+1);
    }
    int query(int cx , int cy , int qx , int qy , int id) {
        if(cy < qx || qy < cx)
            return 0;
        if(qx <= cx && cy <= qy)
            return tree[id];
        int mid = (cx+cy)>>1;
        int l = query(cx,mid,qx,qy,2*id);
        int r = query(mid+1,cy,qx,qy,2*id+1);
        return max(l,r);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans = 0;
        for(int x : nums) {
            int l = max(1,x-k) , r = x-1;
            int val = query(1,maxn,l,r,1)+1;
            ans = max(ans,val);
            update(1,maxn,x,val,1);
        }
        return ans;
    }
};
