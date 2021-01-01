class Solution {
public:
    int minDistance(int height, int width, vector<int>& t, vector<int>& s, vector<vector<int>>& ar) {
        int total = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            total += 2*abs(ar[i][0]-t[0]) + 2*abs(ar[i][1]-t[1]);
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            int cost = total - 2 * ( abs(ar[i][0]-t[0]) + abs(ar[i][1]-t[1]) );
            cost += abs(s[0]-ar[i][0]) + abs(s[1]-ar[i][1]);
            cost += abs(t[0]-ar[i][0]) + abs(t[1]-ar[i][1]);
            ans = min(ans,cost);
        }
        return ans;
    }
};