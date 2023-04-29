class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<int> cnt(n,0);
        for( int i = 0 ; i < m ; i++ ) {
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
        }
        long long ans = 0;
        sort(cnt.begin(),cnt.end());
        for( int i = 0 ; i < n ; i++ ) {
            ans += (long long) (i+1) * cnt[i];
        }
        return ans;
    }
};
