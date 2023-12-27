class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& v) {
        int n = v.size();
        int r = n-1;
        while(r and v[r-1] < v[r])
            r--;
        if(r == 0)
            return (long long) n*(n+1)/2;
        long long ans = n-r+1;
        for( int i = 0 ; i < n ; i++ ) {
            if(i and v[i] <= v[i-1])
                break;
            while(r < n and v[i] >= v[r])
                r++;
            ans += n-r+1;
        }
        return ans;
    }
};
