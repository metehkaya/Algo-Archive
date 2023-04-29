class Solution {
public:
    int minSwaps(vector<int>& ar) {
        int n = ar.size() , k = 0;
        for(int x : ar)
            k += x;
        if(k <= 1 || k == n)
            return 0;
        for( int i = 0 ; i < n ; i++ )
            ar.push_back(ar[i]);
        int cnt = 0;
        for( int i = 0 ; i < k ; i++ )
            cnt += ar[i];
        int ans = k-cnt;
        for( int i = 1 ; i < n ; i++ ) {
            cnt -= ar[i-1];
            cnt += ar[i+k-1];
            ans = min(ans,k-cnt);
        }
        return ans;
    }
};
