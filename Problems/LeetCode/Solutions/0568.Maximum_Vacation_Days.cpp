class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size() , k = days[0].size();
        vector<int> dp(n,-1);
        for( int i = 0 ; i < n ; i++ )
            if(i == 0 or flights[0][i])
                dp[i] = days[i][0];
        for( int d = 1 ; d < k ; d++ ) {
            vector<int> dp_new(n,-1);
            for( int i = 0 ; i < n ; i++ )
                if(dp[i] != -1)
                    for( int j = 0 ; j < n ; j++ )
                        if(i == j or flights[i][j])
                            dp_new[j] = max(dp_new[j] , dp[i]+days[j][d]);
            dp = dp_new;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
