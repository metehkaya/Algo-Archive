class Solution {
public:
    bool isReflected(vector<vector<int>>& ar) {
        int n = ar.size();
        int xmax = INT_MIN;
        int xmin = INT_MAX;
        set<vector<int>> s;
        for( int i = 0 ; i < n ; i++ ) {
            xmax = max(xmax,ar[i][0]);
            xmin = min(xmin,ar[i][0]);
            s.insert(ar[i]);
        }
        int xsum = xmin + xmax;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> v(2);
            v[0] = xsum - ar[i][0];
            v[1] = ar[i][1];
            if(s.find(v) == s.end())
                return false;
        }
        return true;
    }
};