class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        set<int> s({-1, n});
        vector<int> ans(n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int idx = v[i][1];
            auto it = s.upper_bound(idx);
            int r = (*it) - idx;
            it--;
            int l = idx - (*it);
            ans[idx] = l+r-1;
            s.insert(idx);
        }
        return ans;
    }
};
