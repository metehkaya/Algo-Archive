class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& ar) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 1 ; i < n ; i++ )
            ans = max(ans,ar[i]-ar[i-1]-1);
        ans = max(ans,ar[0]-bottom);
        ans = max(ans,top-ar[n-1]);
        return ans;
    }
};
