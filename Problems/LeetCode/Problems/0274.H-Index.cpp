class Solution {
public:
    int hIndex(vector<int>& ar) {
        int n = ar.size() , total = 0;
        vector<int> cnt(n+1);
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] > n)
                total++;
            else
                cnt[ar[i]]++;
        }
        for( int i = n ; i >= 1 ; i-- ) {
            total += cnt[i];
            if(total >= i)
                return i;
        }
        return 0;
    }
};