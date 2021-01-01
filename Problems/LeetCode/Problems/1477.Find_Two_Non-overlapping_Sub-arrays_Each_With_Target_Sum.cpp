class Solution {
public:
    int minSumOfLengths(vector<int>& ar, int target) {
        int n = ar.size();
        vector<int> left(n),right(n);
        map<int,int> indexSum;
        indexSum[0] = -1;
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            auto it = indexSum.find(sum-target);
            int prev = (i == 0) ? INT_MAX : left[i-1];
            if(it != indexSum.end())
                prev = min(prev , i - it->second);
            left[i] = prev;
            indexSum[sum] = i;
        }
        indexSum.clear();
        indexSum[0] = n;
        for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
            sum += ar[i];
            auto it = indexSum.find(sum-target);
            int prev = (i == n-1) ? INT_MAX : right[i+1];
            if(it != indexSum.end())
                prev = min(prev , it->second - i);
            right[i] = prev;
            indexSum[sum] = i;
        }
        int ans = INT_MAX;
        for( int i = 0 ; i < n-1 ; i++ )
            if( max( left[i] , right[i+1] ) < INT_MAX )
                ans = min( ans , left[i] + right[i+1] );
        return (ans == INT_MAX) ? -1 : ans;
    }
};