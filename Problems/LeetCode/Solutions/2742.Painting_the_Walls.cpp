class Solution {
public:
    int n;
    vector<int> cost,time;
    int dp[500][1001];
    int f(int id , int t) {
        if(id == n)
            return (t >= n) ? 0 : INT_MAX;
        if(dp[id][t] != -1)
            return dp[id][t];
        dp[id][t] = INT_MAX;
        int f_val = f(id+1,min(2*n,t+time[id]));
        if(f_val != INT_MAX)
            dp[id][t] = f_val + cost[id];
        f_val = f(id+1,t-1);
        if(f_val != INT_MAX)
            dp[id][t] = min(dp[id][t] , f_val);
        return dp[id][t];
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        this->cost = cost;
        this->time = time;
        memset(dp,-1,sizeof(dp));
        return f(0,n);
    }
};
