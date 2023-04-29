class Solution {
public:
    vector<long long> minimumCosts(vector<int>& e0, vector<int>& e1, int eCost) {
        int n = e0.size();
        vector<long long> dp0(n+1) , dp1(n+1) , ans;
        dp0[0] = 0 , dp1[0] = eCost;
        for( int i = 1 ; i <= n ; i++ ) {
            dp0[i] = min(dp0[i-1]+e0[i-1] , dp1[i-1]+e1[i-1]);
            dp1[i] = min(dp1[i-1]+e1[i-1] , dp0[i-1]+e0[i-1]+eCost);
            ans.push_back(min(dp0[i],dp1[i]));
        }
        return ans;
    }
};
