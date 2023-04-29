class Solution {
public:
    int sumOfBeauties(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        vector<int> mn(n),mx(n);
        mx[0] = ar[0];
        for( int i = 1 ; i < n ; i++ )
            mx[i] = max(mx[i-1],ar[i]);
        mn[n-1] = ar[n-1];
        for( int i = n-2 ; i >= 0 ; i-- )
            mn[i] = min(mn[i+1],ar[i]);
        for( int i = 1 ; i < n-1 ; i++ ) {
            if(mx[i-1] < ar[i] && ar[i] < mn[i+1])
                ans += 2;
            else if(ar[i-1] < ar[i] && ar[i] < ar[i+1])
                ans++;
        }
        return ans;
    }
};