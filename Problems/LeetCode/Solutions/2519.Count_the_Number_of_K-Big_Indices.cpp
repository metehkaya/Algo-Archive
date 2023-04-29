class Solution {
public:
    int n;
    vector<int> tree;
    void update(int idx) {
        while(idx <= n) {
            tree[idx]++;
            idx += (idx & (-idx));
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx) {
            res += tree[idx];
            idx -= (idx & (-idx));
        }
        return res;
    }
    int kBigIndices(vector<int>& nums, int k) {
        n = nums.size();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[nums[i]].push_back(i+1);
        tree.resize(n+1,0);
        int ans = 0;
        for(auto it : mp) {
            vector<int> indices = it.second;
            for(int idx : indices) {
                int cnt_l = query(idx-1);
                int cnt_r = query(n)-query(idx);
                ans += min(cnt_l,cnt_r) >= k;
            }
            for(int idx : indices)
                update(idx);
        }
        return ans;
    }
};
