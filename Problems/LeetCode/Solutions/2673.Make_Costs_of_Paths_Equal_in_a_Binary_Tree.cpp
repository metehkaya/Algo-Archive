class Solution {
public:
    int f(int id , int& ans , vector<int>& cost, int n) {
        if(id > n/2)
            return cost[id-1];
        int l = f(2*id,ans,cost,n);
        int r = f(2*id+1,ans,cost,n);
        ans += abs(l-r);
        return max(l,r)+cost[id-1];
    }
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        f(1,ans,cost,n);
        return ans;
    }
};
