typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    void precalc(vector<int> req[][9]) {
        req[0][2].push_back(1);
        req[0][6].push_back(3);
        req[0][8].push_back(4);
        req[1][7].push_back(4);
        req[2][6].push_back(4);
        req[2][8].push_back(5);
        req[3][5].push_back(4);
        req[6][8].push_back(7);
        for( int i = 0 ; i < 9 ; i++ )
            for( int j = i+1 ; j < 9 ; j++ )
                req[j][i] = req[i][j];
    }
    int numberOfPatterns(int m, int n) {
        vector<int> req[9][9];
        precalc(req);
        queue<pii> Q;
        vector<vector<bool>> mark(9, vector<bool>(1<<9));
        vector<vector<int>> res(9, vector<int>(1<<9));
        for( int i = 0 ; i < 9 ; i++ ) {
            res[i][1<<i] = 1;
            mark[i][1<<i] = true;
            Q.push( pii( pi( i , 1<<i ) , 1 ) );
        }
        int ans = 0;
        while(!Q.empty()) {
            pii tmp = Q.front();
            Q.pop();
            int curr = tmp.first.first;
            int bm = tmp.first.second;
            int cnt = tmp.second;
            if(cnt >= m)
                ans += res[curr][bm];
            if(cnt == n)
                continue;
            for( int i = 0 ; i < 9 ; i++ ) {
                if( bm & (1<<i) )
                    continue;
                bool check = true;
                for( int j = 0 ; j < req[curr][i].size() ; j++ )
                    if( ( bm & ( 1 << req[curr][i][j] ) ) == 0 )
                        check = false;
                if(!check)
                    continue;
                res[i][bm|(1<<i)] += res[curr][bm];
                if(mark[i][bm|(1<<i)])
                    continue;
                mark[i][bm|(1<<i)] = true;
                Q.push( pii( pi( i , bm|(1<<i) ) , cnt+1 ) );
            }
        }
        return ans;
    }
};