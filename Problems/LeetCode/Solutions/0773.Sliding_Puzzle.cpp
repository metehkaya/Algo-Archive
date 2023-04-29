typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<vvi,int> pvvi;

class Solution {
public:
    const int DIR[4][2] = { {0,-1} , {0,+1} , {-1,0} , {+1,0} };
    bool check(vvi& curr) {
        if(curr[0][0] != 1) return false;
        if(curr[0][1] != 2) return false;
        if(curr[0][2] != 3) return false;
        if(curr[1][0] != 4) return false;
        if(curr[1][1] != 5) return false;
        if(curr[1][2] != 0) return false;
        return true;
    }
    int conv(vvi& ar) {
        int val = 0;
        val += 6*6*6*6*6*ar[0][0];
        val += 6*6*6*6*ar[0][1];
        val += 6*6*6*ar[0][2];
        val += 6*6*ar[1][0];
        val += 6*ar[1][1];
        val += ar[1][2];
        return val;
    }
    int slidingPuzzle(vector<vector<int>>& ar) {
        vector<bool> mark(46656,false);
        queue<pvvi> Q;
        mark[conv(ar)] = true;
        Q.push(pvvi(ar,0));
        while(!Q.empty()) {
            vvi curr = Q.front().first;
            int dist = Q.front().second;
            if(check(curr))
                return dist;
            Q.pop();
            int r=-1,c=-1;
            for( int i = 0 ; i < 2 ; i++ )
                for( int j = 0 ; j < 3 ; j++ )
                    if( curr[i][j] == 0 )
                        r=i,c=j;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r + DIR[i][0];
                int y = c + DIR[i][1];
                if(x >= 2 || x < 0 || y >= 3 || y < 0)
                    continue;
                vvi tmp = curr;
                swap(tmp[r][c], tmp[x][y]);
                int markValue = conv(tmp);
                if(mark[markValue])
                    continue;
                mark[markValue] = true;
                Q.push(pvvi(tmp,dist+1));
            }
        }
        return -1;
    }
};