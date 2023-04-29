class DetectSquares {
public:
    int cnt[1001][1001];
    DetectSquares() {
        memset(cnt,0,sizeof(cnt));
    }
    void add(vector<int> p) {
        int x = p[0];
        int y = p[1];
        cnt[x][y]++;
    }
    int f(int x1 , int y1 , int x2 , int y2) {
        if(x2 < 0 || x2 > 1000 || y2 < 0 || y2 > 1000)
            return 0;
        return cnt[x1][y2]*cnt[x2][y1]*cnt[x2][y2];
    }
    int count(vector<int> p) {
        int x = p[0];
        int y = p[1];
        int ans = 0;
        for( int k = 1 ; k <= 1000 ; k++ ) {
            ans += f(x,y,x-k,y-k);
            ans += f(x,y,x-k,y+k);
            ans += f(x,y,x+k,y-k);
            ans += f(x,y,x+k,y+k);
        }
        return ans;
    }
};