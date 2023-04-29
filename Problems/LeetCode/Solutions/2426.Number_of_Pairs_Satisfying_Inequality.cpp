class Solution {
public:
    static const int maxs = 10000;
    static const int maxS = 8*maxs+2;
    int tree[maxS];
    void update(int x) {
        while(x < maxS) {
            tree[x]++;
            x += (x&(-x));
        }
    }
    int query(int x) {
        int res = 0;
        while(x) {
            res += tree[x];
            x -= (x&(-x));
        }
        return res;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        memset(tree,0,sizeof(tree));
        long long ans = 0;
        int n = nums1.size();
        for( int i = 0 ; i < n ; i++ ) {
            int val = nums1[i]-nums2[i];
            ans += query(val+diff+4*maxs);
            update(val+4*maxs);
        }
        return ans;
    }
};
