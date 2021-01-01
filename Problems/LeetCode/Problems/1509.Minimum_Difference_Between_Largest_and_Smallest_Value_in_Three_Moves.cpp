class Solution {
public:
    int minDifference(vector<int>& ar) {
        int n = ar.size();
        if(n <= 4)
            return 0;
        sort(ar.begin(),ar.end());
        int ans = INT_MAX;
        for( int i = 0 , j = n-4 ; i <= 3 ; i++ , j++ )
            ans = min(ans,ar[j]-ar[i]);
        return ans;
    }
};