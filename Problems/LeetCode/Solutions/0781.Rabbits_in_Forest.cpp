class Solution {
public:
    int n,ans;
    int cnt[1000];
    int numRabbits(vector<int>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for( int i = 0 ; i < 1000 ; i++ ) {
            int k = i+1;
            int m = cnt[i];
            ans += k * ((m+k-1)/k);
        }
        return ans;
    }
};