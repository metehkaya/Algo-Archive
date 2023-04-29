class Solution {
public:
    int n,m,lim;
    vector<vector<int>> v;
    bool mark[100][100][100];
    bool f(int i , int j , int k) {
        if(k > lim or mark[i][j][k])
            return false;
        if(i == n-1 and j == m-1)
            return k == lim;
        mark[i][j][k] = true;
        if(i+1 < n and f(i+1,j,k+v[i+1][j]))
            return true;
        if(j+1 < m and f(i,j+1,k+v[i][j+1]))
            return true;
        return false;
    }
    bool isThereAPath(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        if((n+m) % 2 == 0)
            return false;
        lim = (n+m-1)/2;
        memset(mark,false,sizeof(mark));
        this->v = v;
        return f(0,0,v[0][0]);
    }
};
