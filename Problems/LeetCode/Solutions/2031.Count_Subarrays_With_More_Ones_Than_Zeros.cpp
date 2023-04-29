class Solution {
public:
    const int mod = (int) 1e9+7;
    void update(int x , int N , vector<int>& tree) {
        while(x <= N) {
            tree[x]++;
            x += (x&(-x));
        }
    }
    int query(int x , vector<int>& tree) {
        int res = 0;
        while(x) {
            res += tree[x];
            x -= (x&(-x));
        }
        return res;
    }
    int subarraysWithMoreZerosThanOnes(vector<int>& v) {
        int n = v.size();
        int N = 2*n+1;
        vector<int> tree(N+1,0);
        update(n+1,N,tree);
        int ans = 0;
        for( int i = 0 , val = n+1 ; i < n ; i++ ) {
            val += (v[i] == 1 ? 1 : -1);
            ans = (ans + query(val-1,tree)) % mod;
            update(val,N,tree);
        }
        return ans;
    }
};
