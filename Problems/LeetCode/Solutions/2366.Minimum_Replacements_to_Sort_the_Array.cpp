class Solution {
public:
    long long minimumReplacement(vector<int>& ar) {
        long long ans = 0;
        int mx = INT_MAX;
        int n = ar.size();
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(ar[i] <= mx) {
                mx = ar[i];
                continue;
            }
            int divv = (ar[i]/mx) + ((ar[i]%mx) > 0);
            ans += divv-1;
            mx = ar[i]/divv;
        }
        return ans;
    }
};
