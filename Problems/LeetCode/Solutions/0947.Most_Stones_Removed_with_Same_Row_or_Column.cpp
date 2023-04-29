class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& ar, vector<bool>& mark) {
        mark[node] = true;
        for( int i = 0 ; i < n ; i++ )
            if( !mark[i] && ( ar[node][0] == ar[i][0] || ar[node][1] == ar[i][1] ) )
                dfs(i,n,ar,mark);
    }
    int removeStones(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<bool> mark(n);
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                dfs(i,n,ar,mark), cnt++;
        return n-cnt;
    }
};