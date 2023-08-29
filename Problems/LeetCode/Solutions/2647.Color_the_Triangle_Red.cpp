class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        int k = n%4;
        vector<vector<int>> ans;
        if(k >= 1)
            ans.push_back({1,1});
        for( int i = 2 ; i <= k ; i++ ) {
            ans.push_back({i,1});
            ans.push_back({i,2*i-1});
        }
        for( int i = k+1 ; i <= n ; i += 4 ) {
            ans.push_back({i,1});
            for( int j = 1 ; j <= i ; j++ )
                ans.push_back({i+1,2*j+1});
            ans.push_back({i+2,2});
            for( int j = 0 ; j <= i+2 ; j++ )
                ans.push_back({i+3,2*j+1});
        }
        return ans;
    }
};
