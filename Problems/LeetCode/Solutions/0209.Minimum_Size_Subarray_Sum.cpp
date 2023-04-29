class Solution {
public:
    int minSubArrayLen(int target, vector<int>& ar) {
        int n = ar.size() , ans = INT_MAX , sum = 0;
        for( int l = 0 , r = 0 ; l < n ; l++ ) {
            if(l)
                sum -= ar[l-1];
            while(r < n && sum < target)
                sum += ar[r++];
            if(sum >= target)
                ans = min(ans,r-l);
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};