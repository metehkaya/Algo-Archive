class Solution {
public:
    int f(vector<int>& ar , int l , int r , int val) {
        int cnt = 0;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(val >= ar[m])
                cnt = m+1 , l = m+1;
            else
                r = m-1;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        int l = ar[0][0] , r = ar[n-1][m-1];
        int ans = INT_MIN;
        while(l <= r) {
            int cnt = 0;
            int mid = (l+r) >> 1;
            for( int i = 0 ; i < n ; i++ )
                cnt += f(ar[i],0,m-1,mid);
            if(cnt >= k)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};