class Solution {
public:
    int addRungs(vector<int>& ar, int d) {
        int n = ar.size();
        int h = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int diff = ar[i]-h;
            ans += (diff-1) / d;
            h = ar[i];
        }
        return ans;
    }
};