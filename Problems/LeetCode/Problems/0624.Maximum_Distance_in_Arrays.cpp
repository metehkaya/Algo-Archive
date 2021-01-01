class Solution {
public:
    int maxDistance(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        int mn = ar[0][0] , mx = ar[0][ar[0].size()-1];
        for( int i = 1 ; i < n ; i++ ) {
            int x = ar[i][0];
            int y = ar[i][ar[i].size()-1];
            ans = max(ans,y-mn);
            ans = max(ans,mx-x);
            mn = min(mn,x);
            mx = max(mx,y);
        }
        return ans;
    }
};