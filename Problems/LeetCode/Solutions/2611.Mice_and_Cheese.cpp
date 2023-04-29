class Solution {
public:
    int miceAndCheese(vector<int>& x, vector<int>& y, int k) {
        int n = x.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({y[i]-x[i],i});
        sort(v.begin(),v.end());
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(i < k)
                ans += x[v[i][1]];
            else
                ans += y[v[i][1]];
        return ans;
    }
};
