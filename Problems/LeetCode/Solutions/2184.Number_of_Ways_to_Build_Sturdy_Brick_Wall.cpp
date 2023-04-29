class Solution {
public:
    const int mod = (int)1e9+7;
    int dp[100][512];
    vector<int> bmasks,bricks;
    void find_bmasks(int w , int bmask) {
        if(w == 0) {
            bmasks.push_back(bmask);
            return;
        }
        for(int l : bricks) {
            int w2 = w-l , bmask2 = bmask;
            if(w2 < 0)
                continue;
            if(w2)
                bmask2 = (bmask | (1 << (w2-1)));
            find_bmasks(w2, bmask2);
        }
    }
    int f(int row , int last_bmask) {
        if(row == -1)
            return 1;
        if(dp[row][last_bmask] != -1)
            return dp[row][last_bmask];
        dp[row][last_bmask] = 0;
        for(int bmask : bmasks)
            if((bmask & last_bmask) == 0)
                dp[row][last_bmask] = (dp[row][last_bmask] + f(row-1,bmask)) % mod;
        return dp[row][last_bmask];
    }
    int buildWall(int height, int width, vector<int>& bricks) {
        this->bricks = bricks;
        find_bmasks(width,0);
        memset(dp,-1,sizeof(dp));
        return f(height-1,0);
    }
};
