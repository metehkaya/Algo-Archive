class Solution {
public:
    int mat2int(vector<vector<int>>& ar , int n , int m) {
        int sum = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                sum = sum*2 + ar[i][j];
        return sum;
    }
    vector<vector<int>> int2mat(int num , int n , int m) {
        vector<vector<int>> ar(n,vector<int>(m));
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m-1 ; j >= 0 ; j-- ) {
                ar[i][j] = num%2;
                num /= 2;
            }
        return ar;
    }
    vector<vector<int>> change(vector<vector<int>>& ar , int i , int j , int n , int m) {
        vector<vector<int>> out = ar;
        out[i][j] = !out[i][j];
        if(i>0)
            out[i-1][j] = !out[i-1][j];
        if(i<n-1)
            out[i+1][j] = !out[i+1][j];
        if(j>0)
            out[i][j-1] = !out[i][j-1];
        if(j<m-1)
            out[i][j+1] = !out[i][j+1];
        return out;
    }
    int minFlips(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int k = (1 << (n*m));
        int initial = mat2int(ar,n,m);
        queue<int> Q;
        vector<int> dist(k,-1);
        Q.push(initial);
        dist[initial] = 0;
        while(!Q.empty()) {
            int num = Q.front();
            Q.pop();
            if(num == 0)
                return dist[0];
            vector<vector<int>> mat = int2mat(num,n,m);
            for( int i = 0 ; i < n ; i++ )
                for( int j = 0 ; j < m ; j++ ) {
                    vector<vector<int>> mat2 = change(mat,i,j,n,m);
                    int num2 = mat2int(mat2,n,m);
                    if(dist[num2] != -1)
                        continue;
                    Q.push(num2);
                    dist[num2] = dist[num] + 1;
                }
        }
        return -1;
    }
};