typedef long long LL;

class Solution {
public:
    static const int maxn = 100003;
    int tree[4*maxn];
    void update(int cx , int cy , int q , int val , int id) {
        if(cy < q || q < cx)
            return;
        tree[id] = val;
        if(cx == cy)
            return;
        int mid = (cx+cy) >> 1;
        update(cx,mid,q,val,2*id);
        update(mid+1,cy,q,val,2*id+1);
    }
    int query(int cx , int cy , int qx , int qy , int id) {
        if(cy < qx || qy < cx)
            return -1;
        if(qx <= cx && cy <= qy)
            return tree[id];
        int mid = (cx+cy) >> 1;
        int l = query(cx,mid,qx,qy,2*id);
        int r = query(mid+1,cy,qx,qy,2*id+1);
        return (l == -1) ? r : max(l,r);
    }
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<LL> sum(n+1,0);
        set<LL> sum_values_s;
        sum_values_s.insert(0);
        for( int i = 1 ; i <= n ; i++ ) {
            sum[i] = sum[i-1] + nums[i-1];
            sum_values_s.insert(sum[i]);
        }
        vector<LL> sum_values_v(sum_values_s.begin(),sum_values_s.end());
        map<LL,int> dict_sum_values;
        int N = sum_values_v.size();
        for( int i = 0 ; i < N ; i++ )
            dict_sum_values[sum_values_v[i]] = i;
        memset(tree,-1,sizeof(tree));
        update(0,N-1,dict_sum_values[0],0,1);
        int ans = INT_MAX;
        for( int i = 1 ; i <= n ; i++ ) {
            int idx = upper_bound(sum_values_v.begin(),sum_values_v.end(),sum[i]-k) - sum_values_v.begin();
            int rm = query(0,N-1,0,idx-1,1);
            if(rm != -1)
                ans = min(ans,i-rm);
            update(0,N-1,dict_sum_values[sum[i]],i,1);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
