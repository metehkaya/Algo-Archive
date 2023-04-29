class Solution {
public:
    static const int maxn = 100003;
    int n;
    int tree[maxn];
    int query(int x) {
        int res = 0;
        while(x) {
            res += tree[x];
            x -= (x&(-x));
        }
        return res;
    }
    void update(int x) {
        while(x <= n) {
            tree[x]++;
            x += (x&(-x));
        }
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        n = nums1.size();
        vector<int> pos(n);
        for( int i = 1 ; i <= n ; i++ )
            pos[nums2[i-1]] = i;
        for( int i = 1 ; i <= n ; i++ ) {
            int val = nums1[i-1];
            int id = pos[val];
            int l = query(id-1);
            int r = (n-id) - (query(n) - query(id));
            ans += (long long) l*r;
            update(id);
        }
        return ans;
    }
};
