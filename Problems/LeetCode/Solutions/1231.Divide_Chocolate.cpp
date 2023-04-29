class Solution {
public:
    bool check(int minValue, vector<int>& ar, int k) {
        int cnt = 0;
        for( int i = 0 , sum = 0 ; i < ar.size() ; i++ ) {
            sum += ar[i];
            if(sum >= minValue) {
                cnt++;
                sum = 0;
            }
        }
        return cnt > k;
    }
    int maximizeSweetness(vector<int>& ar, int k) {
        int sum = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        int ans = 0 , l = 1 , r = sum / (k+1);
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid,ar,k))
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};