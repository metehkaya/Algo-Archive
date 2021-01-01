class Solution {
public:
    int numTimesAllBlue(vector<int>& ar) {
        int n = ar.size();
        int mx = 0 , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            mx = max( mx , ar[i] );
            if(mx == i+1)
                ans++;
        }
        return ans;
    }
};