class Solution {
public:
    int n;
    vector<int> tree;
    void update(int x) {
        while(x <= n) {
            tree[x]++;
            x += (x&(-x));
        }
    }
    int query(int x) {
        int sum = 0;
        while(x) {
            sum += tree[x];
            x -= (x&(-x));
        }
        return sum;
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums[i],i+1});
        sort(v.begin(),v.end());
        tree.resize(n+1,0);
        long long ans = v[0][1];
        update(v[0][1]);
        for( int i = 1 ; i < n ; i++ ) {
            int idx_old = v[i-1][1];
            int idx_new = v[i][1];
            if(idx_old < idx_new) {
                ans += idx_new - idx_old;
                ans -= query(idx_new) - query(idx_old);
            }
            else {
                ans += n - idx_old;
                ans -= query(n) - query(idx_old);
                ans += idx_new;
                ans -= query(idx_new);
            }
            update(idx_new);
        }
        return ans;
    }
};
