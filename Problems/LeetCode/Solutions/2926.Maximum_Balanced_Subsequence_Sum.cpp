class Solution {
public:
    static const int maxn = (int)1e5+1;
    long long tree[4*maxn];
    long long update(int cx , int cy , int q , long long val , int idx) {
        if(q < cx or cy < q)
            return tree[idx];
        if(cx == cy)
            return tree[idx] = max(tree[idx],val);
        int mid = (cx+cy) >> 1;
        long long l = update(cx,mid,q,val,2*idx+1);
        long long r = update(mid+1,cy,q,val,2*idx+2);
        return tree[idx] = max(l,r);
    }
    long long query(int cx , int cy , int qx , int qy , int idx) {
        if(qy < cx or cy < qx)
            return 0;
        if(qx <= cx and cy <= qy)
            return tree[idx];
        int mid = (cx+cy) >> 1;
        long long l = query(cx,mid,qx,qy,2*idx+1);
        long long r = query(mid+1,cy,qx,qy,2*idx+2);
        return max(l,r);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        if(mx <= 0)
            return mx;
        int n = nums.size();
        set<int> diffs;
        for( int i = 0 ; i < n ; i++ )
            diffs.insert(nums[i]-i);
        int m = 0;
        map<int,int> diff2idx;
        for(int diff : diffs)
            diff2idx[diff] = m++;
        memset(tree,0,sizeof(tree));
        for( int i = 0 ; i < n ; i++ ) {
            int idx = diff2idx[nums[i]-i];
            long long val = query(0,m,0,idx,0) + nums[i];
            if(val > 0)
                update(0,m,idx,val,0);
        }
        return tree[0];
    }
};
