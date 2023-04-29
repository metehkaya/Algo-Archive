class Solution {
public:
    int n,ans;
    vector<vector<int>> ar;
    bool check(int i , int j) {
        long long dx = ar[i][0] - ar[j][0];
        long long dy = ar[i][1] - ar[j][1];
        long long r = ar[i][2];
        return dx*dx+dy*dy <= r*r;
    }
    void dfs(int u, vector<bool>& mark, int& cnt) {
        cnt++;
        mark[u] = true;
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i] && check(u,i))
                dfs(i,mark,cnt);
    }
    int maximumDetonation(vector<vector<int>>& ar) {
        n = ar.size();
        this->ar = ar;
        for( int i = 0 ; i < n ; i++ ) {
            vector<bool> mark(n,false);
            int cnt = 0;
            dfs(i,mark,cnt);
            ans = max(ans,cnt);
        }
        return ans;
    }
};
