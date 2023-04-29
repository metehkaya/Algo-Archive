class Solution {
public:
    const int BIG = (int) 1e6;
    int smallestDivisor(vector<int>& ar, int threshold) {
        int n = ar.size();
        int ans = BIG , l = 1 , r = BIG;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int sum = 0;
            for( int i = 0 ; i < n ; i++ )
                sum += ar[i] / mid + ((ar[i]%mid) > 0);
            if(sum <= threshold)
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};