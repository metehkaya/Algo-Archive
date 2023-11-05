class Solution {
public:
    const int mod = 1e9+7;
    static const int maxn = 100003;
    int tree[4*maxn];
    int lazy[4*maxn];
    void push(int cx , int cy , int id) {
        long long add = cy-cx+1;
        add = add * lazy[id] % mod;
        tree[id] += add;
        tree[id] %= mod;
        if(cx != cy) {
            lazy[2*id+1] += lazy[id];
            lazy[2*id+2] += lazy[id];
        }
        lazy[id] = 0;
    }
    int update(int cx , int cy , int qx , int qy , int id) {
        if(lazy[id])
            push(cx,cy,id);
        if(cy < qx or qy < cx)
            return tree[id];
        if(qx <= cx and cy <= qy) {
            lazy[id]++;
            push(cx,cy,id);
            return tree[id];
        }
        int mid = (cx+cy) >> 1;
        int l = update(cx,mid,qx,qy,2*id+1);
        int r = update(mid+1,cy,qx,qy,2*id+2);
        return tree[id] = (l+r) % mod;
    }
    int query(int cx , int cy , int qx , int qy , int id) {
        if(lazy[id])
            push(cx,cy,id);
        if(cy < qx or qy < cx)
            return 0;
        if(qx <= cx and cy <= qy)
            return tree[id];
        int mid = (cx+cy) >> 1;
        int l = query(cx,mid,qx,qy,2*id+1);
        int r = query(mid+1,cy,qx,qy,2*id+2);
        tree[id] = (tree[2*id+1] + tree[2*id+2]) % mod;
        return (l+r) % mod;
    }
    int sumCounts(vector<int>& nums) {
        memset(tree,0,sizeof(tree));
        memset(lazy,false,sizeof(lazy));
        int n = nums.size() , ans = 0 , sum2 = 0;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ ) {
            auto it = mp.find(nums[i]);
            int last = (it == mp.end()) ? -1 : (*it).second;
            int cnt = i-last;
            int sum = query(0,n-1,last+1,i,0);
            int add = 2*sum % mod;
            add = (add+cnt) % mod;
            sum2 = (sum2+add) % mod;
            ans = (ans+sum2) % mod;
            mp[nums[i]] = i;
            update(0,n-1,last+1,i,0);
        }
        return ans;
    }
};
