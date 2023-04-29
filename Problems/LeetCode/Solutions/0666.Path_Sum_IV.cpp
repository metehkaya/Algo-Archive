class Solution {
public:
    int vals[5][9];
    bool child[5][9];
    int getDepth(int num) {
        return num/100;
    }
    int getPos(int num) {
        return (num/10) % 10;
    }
    int pathSum(vector<int>& ar) {
        int n = ar.size();
        memset(vals,-1,sizeof(vals));
        memset(child,false,sizeof(child));
        for( int i = 0 ; i < n ; i++ ) {
            int d = getDepth(ar[i]);
            int p = getPos(ar[i]);
            vals[d][p] = ar[i]%10;
            child[d-1][(p+1)/2] = true;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int d = getDepth(ar[i]);
            int p = getPos(ar[i]);
            if(!child[d][p]) {
                int x = d , y = p;
                while(x > 0) {
                    ans += vals[x][y];
                    x--;
                    y = (y+1)/2;
                }
            }
        }
        return ans;
    }
};