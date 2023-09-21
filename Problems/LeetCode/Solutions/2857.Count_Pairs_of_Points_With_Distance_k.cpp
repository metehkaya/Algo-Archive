class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans = 0;
        map<int,map<int,int>> mp;
        for(auto v : coordinates) {
            for( int dx = 0 ; dx <= k ; dx++ ) {
                int dy = k-dx;
                int x = v[0]^dx , y = v[1]^dy;
                if(mp.count(x) and mp[x].count(y))
                    ans += mp[x][y];
            }
            mp[v[0]][v[1]]++;
        }
        return ans;
    }
};
