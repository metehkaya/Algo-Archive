class Solution {
public:
    int maxDistToClosest(vector<int>& ar) {
        int n = ar.size();
        int prev = -1 , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if( ar[i] == 1 ) {
                if(prev == -1)
                    ans = i;
                else
                    ans = max(ans, (i-prev)/2);
                prev = i;
            }
        ans = max(ans, n-1-prev);
        return ans;
    }
};