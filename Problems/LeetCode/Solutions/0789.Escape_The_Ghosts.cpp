class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ar, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int dx = abs(t[0]-ar[i][0]);
            int dy = abs(t[1]-ar[i][1]);
            if(dx+dy <= d)
                return false;
        }
        return true;
    }
};