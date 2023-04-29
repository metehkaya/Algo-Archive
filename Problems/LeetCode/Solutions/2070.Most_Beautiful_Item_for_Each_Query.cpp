class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<vector<int>> ar = items;
        for( int i = 0 ; i < m ; i++ )
            ar.push_back({queries[i], -(i+1)});
        sort(ar.begin() , ar.end() , [&](vector<int>& a , vector<int>& b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        int mx = 0;
        vector<int> ans(m);
        for( int i = 0 ; i < n+m ; i++ ) {
            if(ar[i][1] < 0)
                ans[-(ar[i][1]+1)] = mx;
            else
                mx = max(mx,ar[i][1]);
        }
        return ans;
    }
};
