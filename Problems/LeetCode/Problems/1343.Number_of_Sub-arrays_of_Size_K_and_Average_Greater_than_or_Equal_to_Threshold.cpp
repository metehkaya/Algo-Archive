class Solution {
public:
    int numOfSubarrays(vector<int>& ar, int k, int threshold) {
        int ans = 0;
        int sum = 0;
        int n = ar.size();
        for( int i = 0 ; i < k ; i++ )
            sum += ar[i];
        if(sum >= k*threshold)
            ans++;
        for( int i = k ; i < n ; i++ ) {
            sum += ar[i] - ar[i-k];
            if(sum >= k*threshold)
                ans++;
        }
        return ans;
    }
};