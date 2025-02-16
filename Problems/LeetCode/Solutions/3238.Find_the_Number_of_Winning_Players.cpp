class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<bool> ok(n,false);
        vector<map<int,int>> mp(n);
        for(auto p : pick) {
            int x = p[0] , y = p[1];
            if(++mp[x][y] > x)
                ok[x] = true;
        }
        int ans = 0;
        for(bool add : ok)
            ans += add;
        return ans;
    }
};