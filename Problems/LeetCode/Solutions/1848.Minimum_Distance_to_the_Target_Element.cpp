class Solution {
public:
    int getMinDistance(vector<int>& ar, int target, int start) {
        int n = ar.size() , ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == target)
                ans = min(ans,abs(i-start));
        return ans;
    }
};