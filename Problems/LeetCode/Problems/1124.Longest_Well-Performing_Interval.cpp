class Solution {
public:
    void update(int i , int val , vector<int>& tree , int mx) {
        while(i <= mx) {
            tree[i] = min(tree[i],val);
            i += (i & (-i));
        }
    }
    int query(int i , vector<int>& tree) {
        int mn = INT_MAX;
        while(i > 0) {
            mn = min(mn,tree[i]);
            i -= (i & (-i));
        }
        return mn;
    }
    int longestWPI(vector<int>& ar) {
        int n = ar.size();
        vector<int> v(n+1,n+1);
        vector<int> tree(2*n+2,n+1);
        update(n+1,0,tree,2*n+1);
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int add = (ar[i-1] > 8) ? +1 : -1;
            v[i] = v[i-1] + add;
            int mn = query(v[i]-1,tree);
            if(mn < i)
                ans = max(ans,i-mn);
            update(v[i],i,tree,2*n+1);
        }
        return ans;
    }
};