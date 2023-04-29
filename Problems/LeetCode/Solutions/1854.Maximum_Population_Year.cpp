class Solution {
public:
    int cnt[2051];
    int sum[2051];
    int maximumPopulation(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            cnt[ar[i][0]]++;
            cnt[ar[i][1]]--;
        }
        int ans = 1950;
        for( int i = 1950 ; i <= 2050 ; i++ ) {
            sum[i] = sum[i-1]+cnt[i];
            if(sum[i] > sum[ans])
                ans = i;
        }
        return ans;
    }
};