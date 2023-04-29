class Solution {
public:
    int n;
    int dp[1000][1000];
    vector<int> ar;
    map<int,int> mp;
    int getid(int num) {
        map<int,int>::iterator it = mp.find(num);
        if(it == mp.end())
            return -1;
        return it->second;
    }
    int f(int x , int y) {
        if(dp[x][y] != -1)
            return dp[x][y];
        int z = getid(ar[x]+ar[y]);
        if(z == -1)
            dp[x][y] = 0;
        else
            dp[x][y] = f(y,z)+1;
        return dp[x][y];
    }
    int lenLongestFibSubseq(vector<int>& ar) {
        n = ar.size();
        this->ar = ar;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]] = i;
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                ans = max(ans,f(i,j)+2);
        if(ans < 3)
            return 0;
        return ans;
    }
};