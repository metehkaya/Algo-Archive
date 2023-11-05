class Solution {
public:
    static const int maxp = 5000;
    int tree[4*maxp+1];
    int update(int cx , int cy , int q , int val , int id) {
        if(cy < q or q < cx)
            return tree[id];
        if(cx == cy)
            return tree[id] = max(tree[id],val);
        int mid = (cx + cy) >> 1;
        int l = update(cx,mid,q,val,2*id+1);
        int r = update(mid+1,cy,q,val,2*id+2);
        return tree[id] = max(l,r);
    }
    int query(int cx , int cy , int qx , int qy , int id) {
        if(cy < qx or qy < cx)
            return 0;
        if(qx <= cx and cy <= qy)
            return tree[id];
        int mid = (cx + cy) >> 1;
        int l = query(cx,mid,qx,qy,2*id+1);
        int r = query(mid+1,cy,qx,qy,2*id+2);
        return max(l,r);
    }
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size() , ans = -1;
        vector<int> dp1(n) , dp2(n);
        memset(tree,0,sizeof(tree));
        for( int i = 0 ; i < n ; i++ ) {
            dp1[i] = query(1,maxp,1,prices[i]-1,0);
            update(1,maxp,prices[i],profits[i],0);
        }
        memset(tree,0,sizeof(tree));
        for( int i = n-1 ; i >= 0 ; i-- ) {
            dp2[i] = query(1,maxp,prices[i]+1,maxp,0);
            update(1,maxp,prices[i],profits[i],0);
        }
        for( int i = 0 ; i < n ; i++ )
            if(dp1[i] > 0 and dp2[i] > 0)
                ans = max(ans,dp1[i]+dp2[i]+profits[i]);
        return ans;
    }
};
