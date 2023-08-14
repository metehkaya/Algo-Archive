class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& coordinates) {
        unordered_set<int> s[n];
        for(auto coordinate : coordinates)
            s[coordinate[0]].insert(coordinate[1]);
        vector<long long> ans(5,0);
        for(auto coordinate : coordinates) {
            int r = coordinate[0] , c = coordinate[1];
            for( int x = r-1 ; x <= r ; x++ )
                for( int y = c-1 ; y <= c ; y++ )
                    if(x >= 0 and x+1 < n and y >= 0 and y+1 < m) {
                        int cnt = s[x].count(y) + s[x].count(y+1) + s[x+1].count(y) + s[x+1].count(y+1);
                        ans[cnt]++;
                    }
        }
        for( int cnt = 1 ; cnt <= 4 ; cnt++ )
            ans[cnt] /= cnt;
        ans[0] = (long long) (n-1)*(m-1);
        for( int cnt = 1 ; cnt <= 4 ; cnt++ )
            ans[0] = ans[0] - ans[cnt];
        return ans;
    }
};
