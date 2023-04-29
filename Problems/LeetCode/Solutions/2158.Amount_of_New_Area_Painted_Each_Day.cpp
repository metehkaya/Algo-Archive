class Solution {
public:
    static const int maxn = 50000;
    int tree[4*maxn];
    bool lazy[4*maxn];
    int query(int cx , int cy , int qx , int qy , int id) {
        if(lazy[id]) {
            lazy[id] = false;
            tree[id] = cy-cx+1;
            if(cx != cy)
                lazy[2*id+1] = lazy[2*id+2] = true;
        }
        if(qy < cx or cy < qx)
            return 0;
        if(qx <= cx and cy <= qy)
            return tree[id];
        int mid = (cx+cy) >> 1;
        int l = query(cx,mid,qx,qy,2*id+1);
        int r = query(mid+1,cy,qx,qy,2*id+2);
        return l+r;
    }
    int update(int cx , int cy , int qx , int qy , int id) {
        if(lazy[id]) {
            lazy[id] = false;
            tree[id] = cy-cx+1;
            if(cx != cy)
                lazy[2*id+1] = lazy[2*id+2] = true;
        }
        if(qy < cx or cy < qx)
            return tree[id];
        if(qx <= cx and cy <= qy) {
            tree[id] = cy-cx+1;
            if(cx != cy)
                lazy[2*id+1] = lazy[2*id+2] = true;
            return tree[id];
        }
        int mid = (cx+cy) >> 1;
        int l = update(cx,mid,qx,qy,2*id+1);
        int r = update(mid+1,cy,qx,qy,2*id+2);
        return tree[id] = l+r;
    }
    vector<int> amountPainted(vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& v : queries) {
            int l = v[0] , r = v[1]-1;
            int q = query(0,maxn-1,l,r,0);
            ans.push_back(r-l+1-q);
            update(0,maxn-1,l,r,0);
        }
        return ans;
    }
};
