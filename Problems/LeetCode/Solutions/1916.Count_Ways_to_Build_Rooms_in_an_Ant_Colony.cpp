class Solution {
public:
    const int mod = (int) 1e9+7;
    int calc_power(int x , int y) {
        if(y == 0)
            return 1;
        long long res = calc_power(x,y/2);
        res = (res * res) % mod;
        if(y & 1)
            res = (res * x) % mod;
        return res;
    }
    int dfs(int u , vector<vector<int>>& adj , vector<int>& cnt) {
        int sum = 0;
        for(int v : adj[u]) {
            int add = dfs(v,adj,cnt);
            cnt[add]--;
            sum += add;
        }
        cnt[sum]++;
        return sum+1;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> adj(n);
        for( int i = 1 ; i < n ; i++ )
            adj[prevRoom[i]].push_back(i);
        vector<int> cnt(n,0);
        dfs(0,adj,cnt);
        long long ans = 1 , x = 1;
        for( int i = 1 ; i < n ; i++ ) {
            x = (x * i) % mod;
            int y = (cnt[i] + mod-1) % (mod-1);
            ans = (ans * calc_power(x,y)) % mod;
        }
        return ans;
    }
};
