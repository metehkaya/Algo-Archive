class Solution {
public:
    int query( int x , vector<int>& tree ) {
        int ans = 0;
        while(x) {
            ans += tree[x];
            x -= (x & (-x));
        }
        return ans;
    }
    void update( int x , int n , vector<int>& tree ) {
        while(x <= n) {
            tree[x]++;
            x += (x & (-x));
        }
    }
    vector<int> countSmaller(vector<int>& ar) {
        int n = ar.size();
        vector<int> v = ar;
        sort( v.begin() , v.end() );
        map<int,int> hashh;
        int k = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            hashh[v[i]] = ++k;
            while(j < n && v[i] == v[j])
                j++;
        }
        vector<int> ans(n);
        vector<int> tree(k+1,0);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int val = hashh[ar[i]];
            ans[i] = query(val-1,tree);
            update(val,k,tree);
        }
        return ans;
    }
};